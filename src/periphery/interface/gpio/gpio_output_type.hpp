//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio_general.h"

namespace kvadro::periphery::interface::gpio
{

class GpioOutputType : public GpioGeneral
{
public:
  GpioOutputType():mOutputType(0){}
  virtual ~GpioOutputType() = default;

  virtual void SetOutputType(GPIO_TypeDef* gpio, uint8_t pin) noexcept
  {
    const uint8_t OUTPUT_TYPE_BITS = 1;
    auto read_data = gpio->OTYPER;

    for(uint8_t i = 0; i < COUNT_PINS; ++i)
    {
      if(IsActivePin(pin, i))
      {
        read_data |= mOutputType << i * OUTPUT_TYPE_BITS;
      }
    }
    gpio->OTYPER = read_data;
  }

protected:
  uint8_t mOutputType;
};
using GpioOutputTypePtr = std::shared_ptr<GpioOutputType>;
}