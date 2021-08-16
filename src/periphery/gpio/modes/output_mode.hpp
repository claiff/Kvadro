//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_mode.hpp"

namespace kvadro::periphery::gpio::mode
{

  class OutputMode : public periphery::types::gpio::GpioMode
  {
  public:
	OutputMode() = default;
	~OutputMode() override = default;

	void SetMode( GPIO_TypeDef *gpio, uint16_t pin ) noexcept override;
  };

}