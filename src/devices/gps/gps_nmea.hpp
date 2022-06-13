//
// Created by claiff on 9/11/21.
//

#pragma once

#include "headers/gprmc.hpp"

namespace device::gps
{
	//TODO Нужно сделать registrator для наполнения хедерами
  class GPS_NMEA : public headers::GPRMC
  {
  public:
	GPS_NMEA() = default;
	~GPS_NMEA() override = default;
  };
}



