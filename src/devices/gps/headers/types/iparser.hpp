//
// Created by claiff on 9/18/21.
//

#pragma once

namespace device::gps::headers::types
{
  static int const MINIMUM_DATA = 20;
  class IParser
  {
  public:
	virtual ~IParser() = default;

	virtual void ProcessData( uint8_t data ) = 0;
	virtual std::string GetField( uint8_t number ) const = 0;
	bool IsParsed()
	{
	  return mDataParsed;
	}
  protected:
	bool mDataParsed;
  };
}