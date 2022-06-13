//
// Created by claiff on 9/18/21.
//

#include <algorithm>
#include <sstream>
#include <iomanip>
#include "parser.hpp"
#include "gprmc.hpp"

namespace device::gps::headers
{
  //
  // Constructors
  //

  Parser::Parser( std::string const& field, uint8_t count_field ) :
	  mField( field ),
	  mCountField( count_field ),
	  mData( {} )
  {
	mDataParsed = false;
  }

  //
  //Public methods
  //

  void Parser::ProcessData( uint8_t data )
  {
	mData.push_back( data );

	if( !mIsFound && !FindHeader() )
	{
	  return;
	}
	if( GetCountFields() < mCountField )
	{
	  return;
	}
	ParseData();
  }

  std::string Parser::GetField( uint8_t number ) const
  {
	if( number > mParsedData.size() )
	{
	  return {};
	}
	return mParsedData[number];
  }

  //
  //Private methods
  //

  bool Parser::FindHeader()
  {
	if( !IsEnoughData() )
	{
	  return mIsFound;
	}
	auto position = GetHeaderPosition();
	if( position == std::string::npos )
	{
	  mData.clear();
	  return mIsFound;
	}
	ClearOnPosition( position );
	mIsFound = true;

	return mIsFound;
  }

  bool Parser::IsEnoughData() const
  {
	return mData.size() >= types::MINIMUM_DATA;
  }

  unsigned int Parser::GetHeaderPosition() const
  {
	return mData.find( mField );
  }

  void Parser::ClearOnPosition( uint8_t position )
  {
	static uint8_t const FIRST_POSITION = 0;
	mData.erase( FIRST_POSITION, position );
  }

  uint8_t Parser::GetCountFields() const
  {
	uint8_t count = std::count_if( mData.begin(), mData.end(), []( unsigned char element ) { return element == ','; } );
	return count;
  }

  void Parser::ParseData()
  {
	static constexpr uint8_t ZERO_POSITION = 0;
	std::string delimiter = ",";
	auto buffer_copy = mData;

	size_t pos = ZERO_POSITION;
	mParsedData.clear();
	while( ( pos = buffer_copy.find( delimiter ) ) != std::string::npos )
	{
	  mParsedData.push_back( buffer_copy.substr( ZERO_POSITION, pos ) );
	  buffer_copy.erase( ZERO_POSITION, pos + delimiter.length() );
	}
	mData.clear();
	mIsFound = false;
  }
}