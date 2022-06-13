//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_mode.hpp"

namespace periphery::gpio::mode
{

  class AnalogMode : public periphery::types::gpio::GpioMode
  {
  public:
	AnalogMode() = default;
	~AnalogMode() override = default;

	void SetMode( GPIO_TypeDef *gpio, uint16_t pin ) noexcept override;
  };

}