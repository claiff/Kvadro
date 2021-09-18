//
// Created by claiff on 9/18/21.
//

#pragma once

#include "types/iheader.hpp"
#include "parser.hpp"

namespace kvadro::device::gps::headers
{
  struct COORDINATE
  {
	uint8_t gradus;
	uint8_t minute;
	uint16_t second;
	char direction;
  };

  struct DateTime
  {
	uint8_t day;
	uint8_t month;
	uint16_t year;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
  };

  class GPRMC : public types::IHeader
  {
  public:
	GPRMC();
	~GPRMC() override = default;

	virtual DateTime GetTime();
	virtual bool IsReliably();
	virtual COORDINATE GetLatitude();
	virtual COORDINATE GetLongitude();
	virtual float GetSpeed();
	virtual float GetDirection();
	void AddData( uint8_t data ) override;
  protected:
	Parser mParser;
  private:
	void FillTime( DateTime& result ) const;
	[[nodiscard]] std::string GetTimeField() const;
	void FillDate( DateTime& result ) const;
	[[nodiscard]] std::string GetDateField() const;
  };

}
