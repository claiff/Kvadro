//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_pull.hpp"

namespace kvadro::periphery::gpio::pull
{

  class PullDown : public periphery::types::gpio::GpioPull
  {
  public:
	PullDown() = default;
	~PullDown() override = default;

	void SetPull( GPIO_TypeDef *gpio, uint8_t pin ) noexcept override;
  };

}