//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio_general.h"

namespace kvadro::periphery::interface::gpio
{

class GpioSpeed : public GpioGeneral
{
public:
  GpioSpeed():mSpeed(0){}
  virtual ~GpioSpeed() = default;

  virtual void SetSpeed(GPIO_TypeDef *gpio, uint8_t pin, uint8_t speed) noexcept
  {
    const uint8_t SPEED_BITS = 2;
    auto read_data = gpio->OSPEEDR;

    for(uint8_t i = 0; i < COUNT_PINS; ++i)
    {
      if(IsActivePin(pin, i))
      {
        read_data |= mSpeed << i * SPEED_BITS;
      }
    }
    gpio->OSPEEDR = read_data;
  }

protected:
  uint8_t mSpeed;
};
using GpioSpeedPtr = std::shared_ptr<GpioSpeed>;
}