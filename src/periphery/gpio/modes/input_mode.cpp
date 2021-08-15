//
// Created by claiff on 6/13/21.
//

#include "input_mode.hpp"

namespace kvadro::periphery::gpio::mode
{
  static const int INPUT_MODE = 0x00;

  InputMode::InputMode() :
	  interface::gpio::GpioMode( INPUT_MODE )
  {
  }

}