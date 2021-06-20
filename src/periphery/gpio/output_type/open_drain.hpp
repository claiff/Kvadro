//
// Created by claiff on 6/13/21.
//
#include "../../interface/gpio/gpio_output_type.hpp"

#pragma once

namespace kvadro::periphery::gpio::output_type
{

class OpenDrainType : public periphery::interface::gpio::GpioOutputType
{
public:
  OpenDrainType() = default;
  ~OpenDrainType() override = default;

  void SetOutputType(GPIO_TypeDef* gpio, uint8_t pin) noexcept override;
};

}