//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio_general.hpp"
#include "memory"
namespace kvadro::periphery::interface::gpio
{
  class GpioOutputType : public GpioGeneral
  {
  public:
	explicit GpioOutputType( uint8_t output_type );
	virtual ~GpioOutputType() = default;

	virtual void SetOutputType( GPIO_TypeDef *gpio, uint16_t group_pins ) noexcept;
  private:

	uint8_t mOutputType;
  };
  using GpioOutputTypePtr = std::shared_ptr<GpioOutputType>;
}