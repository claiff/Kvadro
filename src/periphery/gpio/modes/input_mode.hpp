//
// Created by claiff on 6/13/21.
//

#pragma once

#include "../../types/gpio/gpio_mode.hpp"

namespace kvadro::periphery::gpio::mode
{

  class InputMode : public interface::gpio::GpioMode
  {
  public:
	InputMode();
	~InputMode() override = default;
  };

}