//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_output_type.hpp"

namespace kvadro::periphery::gpio::output_type
{

  class PushPullType : public periphery::types::gpio::GpioOutputType
  {
  public:
	PushPullType();
	~PushPullType() override = default;

	void SetOutputType( GPIO_TypeDef *gpio, uint16_t group_pins ) noexcept override;
  };

}