//
// Created by claiff on 6/13/21.
//

#include "very_high_speed.hpp"

namespace kvadro::periphery::gpio::speed
{
  static const int VERY_HIGH_SPEED = 0x03;

  VeryHighSpeed::VeryHighSpeed() :
	  GpioSpeed( VERY_HIGH_SPEED )
  {
  }
}