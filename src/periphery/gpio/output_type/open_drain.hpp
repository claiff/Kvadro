//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_output_type.hpp"

namespace periphery::gpio::output_type
{

  class OpenDrainType : public periphery::types::gpio::GpioOutputType
  {
  public:
	OpenDrainType();
	~OpenDrainType() override = default;

	//void SetOutputType(GPIO_TypeDef* gpio, uint8_t pin) noexcept override;
  };

}