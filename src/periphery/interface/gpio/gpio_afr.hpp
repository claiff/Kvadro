//
// Created by claiff on 6/13/21.
//

#pragma once

#include "../../../main/stm32f407xx.h"
#include "memory"

namespace kvadro::periphery::interface
{

enum class GPIO_PIN : uint16_t
{
  PIN1 = 0x01,
  PIN2,
  PIN3,
  PIN4,
  PIN5,
  PIN6 ,
  PIN7,
  PIN8,
  PIN9,
  PIN10,
  PIN11,
  PIN12,
  PIN13,
  PIN14,
  PIN15,
};

class GpioMode {
public:
  GpioMode():mMode(0){}
  virtual ~GpioMode() = default;

  virtual void SetMode(GPIO_TypeDef* gpio, uint16_t pin) noexcept
  {
    auto read_data = gpio->MODER;
    read_data |= mMode << pin;
    gpio->MODER = read_data;
  }

protected:
  uint8_t mMode;
};
using GPIO_MODEPtr = std::shared_ptr<GpioMode>;
}