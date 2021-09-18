//
// Created by claiff on 6/13/21.
//

#include "high_speed.hpp"

namespace kvadro::periphery::gpio::speed
{
  const int HIGH_SPEED = 0x02;

  HighSpeed::HighSpeed() :
	  GpioSpeed( HIGH_SPEED )
  {
  }
}