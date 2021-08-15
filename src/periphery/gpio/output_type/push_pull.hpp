//
// Created by claiff on 6/13/21.
//
#include "../../types/gpio/gpio_output_type.hpp"

#pragma once

namespace kvadro::periphery::gpio::output_type
{

  class PushPullType : public periphery::interface::gpio::GpioOutputType
  {
  public:
	PushPullType();
	~PushPullType() override = default;

	void SetOutputType( GPIO_TypeDef *gpio, uint16_t group_pins ) noexcept override;
  };

}