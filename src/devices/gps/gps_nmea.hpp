//
// Created by claiff on 9/11/21.
//

#pragma once

#include "headers/gprmc.hpp"

namespace kvadro::device::gps
{
  class GPS_NMEA : public headers::GPRMC
  {
  public:
	GPS_NMEA() = default;
	~GPS_NMEA() override = default;
  };
}



