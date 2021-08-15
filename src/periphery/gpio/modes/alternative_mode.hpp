//
// Created by claiff on 6/13/21.
//
#include "../../types/gpio/gpio_afr.hpp"
#include "../../types/gpio/gpio_mode.hpp"

#pragma once

namespace kvadro::periphery::gpio::mode
{

  class AlternativeMode : public interface::gpio::GpioMode
  {
  public:
	AlternativeMode();
	~AlternativeMode() override = default;

  };

}