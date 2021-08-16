//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_mode.hpp"

namespace kvadro::periphery::gpio::mode
{

  class InputMode : public types::gpio::GpioMode
  {
  public:
	InputMode();
	~InputMode() override = default;
  };

}