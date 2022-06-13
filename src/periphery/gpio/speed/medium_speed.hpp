//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_speed.hpp"

namespace periphery::gpio::speed
{

  class MediumSpeed : public periphery::types::gpio::GpioSpeed
  {
  public:
	MediumSpeed();
	~MediumSpeed() override = default;
  };

}