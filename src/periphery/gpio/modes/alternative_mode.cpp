//
// Created by claiff on 6/13/21.
//

#include "alternative_mode.hpp"

namespace periphery::gpio::mode
{
  static const int ALTERNATIVE_MODE = 0x02;

  AlternativeMode::AlternativeMode() :
	  types::gpio::GpioMode( ALTERNATIVE_MODE )
  {

  }
}