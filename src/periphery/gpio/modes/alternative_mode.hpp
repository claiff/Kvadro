//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_afr.hpp"
#include "periphery/types/gpio/gpio_mode.hpp"

namespace kvadro::periphery::gpio::mode
{

  class AlternativeMode : public types::gpio::GpioMode
  {
  public:
	AlternativeMode();
	~AlternativeMode() override = default;

  };

}