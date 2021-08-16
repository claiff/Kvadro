//
// Created by claiff on 6/13/21.
//

#include "alternative_mode.hpp"

namespace kvadro::periphery::gpio::mode
{
  const int ALTERNATIVE_MODE = 0x02;

  AlternativeMode::AlternativeMode() :
	  types::gpio::GpioMode( ALTERNATIVE_MODE )
  {

  }
}