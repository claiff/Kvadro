//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_speed.hpp"

namespace kvadro::periphery::gpio::speed
{

  class LowSpeed : public periphery::types::gpio::GpioSpeed
  {
  public:
	LowSpeed() = default;
	~LowSpeed() override = default;

	void SetSpeed( GPIO_TypeDef *gpio, uint8_t pin, uint8_t speed ) noexcept override;
  };

}