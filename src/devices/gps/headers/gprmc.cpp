//
// Created by claiff on 9/18/21.
//

#include "gprmc.hpp"
#include <iomanip>

static char const *const GPRMC_FIELD = "$GPRMC";
static const int COUNT_FIELDS = 12;
static constexpr uint8_t SIZE_FIELD = 2;
namespace device::gps::headers
{
  //
  //Constructors
  //

  GPRMC::GPRMC() :
	  mParser( GPRMC_FIELD, COUNT_FIELDS )
  {
  }

  //
  //Public methods
  //

  void GPRMC::AddData( uint8_t data )
  {
	mParser.ProcessData( data );
  }

  DateTime GPRMC::GetTime()
  {
	//TODO Может optional?

	DateTime result{};

	FillTime( result );
	FillDate( result );

	return result;
  }

  bool GPRMC::IsReliably()
  {
	static constexpr uint8_t RELIABLY_FIELD = 2;
	static const std::string STABLE_STATE = "A";

	auto state = mParser.GetField( RELIABLY_FIELD );
	return state == STABLE_STATE;
  }

  COORDINATE GPRMC::GetLatitude()
  {
	static constexpr uint8_t LATITUDE_FIELD = 3;
	static constexpr uint8_t DIRECTION_FIELD = 4;
	static constexpr uint8_t GRADUS_POSITION = 0;
	static constexpr uint8_t MINUTE_POSITION = 2;
	static constexpr uint8_t SECOND_POSITION = 5;
	static constexpr uint8_t SIZE_SECOND_FIELD = 4;

	COORDINATE result{};

	auto latitude_as_string = mParser.GetField( LATITUDE_FIELD );
	if( latitude_as_string.empty() )
	{
	  return result;
	}

	result.gradus = std::stoi( latitude_as_string.substr( GRADUS_POSITION, SIZE_FIELD ) );
	result.minute = std::stoi( latitude_as_string.substr( MINUTE_POSITION, SIZE_FIELD ) );
	result.second = std::stoi( latitude_as_string.substr( SECOND_POSITION, SIZE_SECOND_FIELD ) );
	result.direction = mParser.GetField( DIRECTION_FIELD )[0];
	return result;
  }

  COORDINATE GPRMC::GetLongitude()
  {
	static constexpr uint8_t LONGTITUDE_FIELD = 5;
	static constexpr uint8_t DIRECTION_FIELD = 6;
	static constexpr uint8_t SIZE_GRADUS_FIELD = 3;
	static constexpr uint8_t GRADUS_POSITION = 0;
	static constexpr uint8_t MINUTE_POSITION = 3;
	static constexpr uint8_t SECOND_POSITION = 6;
	static constexpr uint8_t SIZE_SECOND_FIELD = 4;

	COORDINATE result{};

	auto longtitude_as_string = mParser.GetField( LONGTITUDE_FIELD );
	if( longtitude_as_string.empty() )
	{
	  return result;
	}

	result.gradus = std::stoi( longtitude_as_string.substr( GRADUS_POSITION, SIZE_GRADUS_FIELD ) );
	result.minute = std::stoi( longtitude_as_string.substr( MINUTE_POSITION, SIZE_FIELD ) );
	result.second = std::stoi( longtitude_as_string.substr( SECOND_POSITION, SIZE_SECOND_FIELD ) );
	result.direction = mParser.GetField( DIRECTION_FIELD )[0];
	return result;
  }

  float GPRMC::GetSpeed()
  {
	static constexpr uint8_t SPEED_FIELD = 6;

	auto speed_as_string = mParser.GetField( SPEED_FIELD );
	if( speed_as_string.empty() )
	{
	  return {};
	}
	return std::stof( speed_as_string );
  }

  float GPRMC::GetDirection()
  {
	static constexpr uint8_t DIRECTION_FIELD = 7;

	auto direction_as_string = mParser.GetField( DIRECTION_FIELD );
	if( direction_as_string.empty() )
	{
	  return {};
	}
	return std::stof( direction_as_string );
  }

  //
  //Private methods
  //

  void GPRMC::FillTime( DateTime& result ) const
  {
	static constexpr uint8_t HOUR_FIELD = 0;
	static constexpr uint8_t MINUTE_FIELD = 2;
	static constexpr uint8_t SECOND_FIELD = 4;

	auto time_as_string = GetTimeField();
	if( time_as_string.empty() )
	{
	  return;
	}
	result.hour = std::stoi( time_as_string.substr( HOUR_FIELD, SIZE_FIELD ) );
	result.minute = std::stoi( time_as_string.substr( MINUTE_FIELD, SIZE_FIELD ) );
	result.second = std::stoi( time_as_string.substr( SECOND_FIELD, SIZE_FIELD ) );
  }

  std::string GPRMC::GetTimeField() const
  {
	static constexpr uint8_t TIME_FIELD = 1;

	return mParser.GetField( TIME_FIELD );
  }

  void GPRMC::FillDate( DateTime& result ) const
  {
	static constexpr uint8_t DAY_FIELD = 0;
	static constexpr uint8_t MONTH_FIELD = 2;
	static constexpr uint8_t YEAR_FIELD = 4;

	auto date_as_string = GetDateField();
	if( date_as_string.empty() )
	{
	  return;
	}

	result.day = std::stoi( date_as_string.substr( DAY_FIELD, SIZE_FIELD ) );
	result.month = std::stoi( date_as_string.substr( MONTH_FIELD, SIZE_FIELD ) );
	result.year = std::stoi( date_as_string.substr( YEAR_FIELD, SIZE_FIELD ) );
  }

  std::string GPRMC::GetDateField() const
  {
	static constexpr uint8_t DATE_FIELD = 9;

	return mParser.GetField( DATE_FIELD );
  }
}