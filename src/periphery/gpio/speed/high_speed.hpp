//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_speed.hpp"

namespace periphery::gpio::speed
{

  class HighSpeed : public periphery::types::gpio::GpioSpeed
  {
  public:
	HighSpeed();
	HighSpeed( uint8_t speed );
	~HighSpeed() override = default;
  };

}