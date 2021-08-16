//
// Created by claiff on 6/13/21.
//

#pragma once

#include <memory>

#include "periphery/types/gpio/gpio_general.hpp"

namespace kvadro::periphery::gpio::alternative_func
{

  class AlternativeFunction : public types::gpio::GpioGeneral
  {
  public:
	explicit AlternativeFunction( uint8_t function );
	~AlternativeFunction() override = default;

	void SetFunction( GPIO_TypeDef *gpio, uint16_t pin ) noexcept;

  private:
	uint8_t mFunction;
  };
  using AlternativeFunctionPtr = std::shared_ptr<AlternativeFunction>;
}