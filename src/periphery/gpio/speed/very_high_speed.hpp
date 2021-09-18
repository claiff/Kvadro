//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_speed.hpp"

namespace kvadro::periphery::gpio::speed
{

  class VeryHighSpeed : public periphery::types::gpio::GpioSpeed
  {
  public:
	VeryHighSpeed();
	~VeryHighSpeed() override = default;

  };

}