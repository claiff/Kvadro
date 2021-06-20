//
// Created by claiff on 6/13/21.
//

#pragma once

#include "gpio_general.h"

namespace kvadro::periphery::interface::gpio
{

enum class GPIO_PIN : uint16_t
{
  PIN0 = 1 << 0,
  PIN1 = 1 << 1,
  PIN2 = 1 << 2,
  PIN3 = 1 << 3,
  PIN4 = 1 << 4,
  PIN5 = 1 << 5,
  PIN6 = 1 << 6,
  PIN7 = 1 << 7,
  PIN8,
  PIN9,
  PIN10,
  PIN11,
  PIN12,
  PIN13,
  PIN14,
  PIN15,
};

class GpioMode : public GpioGeneral
{
public:
  GpioMode():mMode(0){}
  virtual ~GpioMode() = default;

  virtual void SetMode(GPIO_TypeDef* gpio, uint16_t pin) noexcept
  {
    const uint8_t MODE_BITS = 2;
    auto read_data = gpio->MODER;

    for(uint8_t i = 0; i < COUNT_PINS; ++i)
    {
      if(IsActivePin(pin, i))
      {
        read_data |= mMode << i * MODE_BITS;
      }
    }
    gpio->MODER = read_data;
  }

protected:
  uint8_t mMode;
};
using GPIO_ModePtr = std::shared_ptr<GpioMode>;
}