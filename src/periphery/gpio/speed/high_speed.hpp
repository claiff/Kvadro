//
// Created by claiff on 6/13/21.
//
#include "../../types/gpio/gpio_speed.hpp"

#pragma once

namespace kvadro::periphery::gpio::speed
{

class HighSpeed : public periphery::interface::gpio::GpioSpeed
{
public:
  HighSpeed() = default;
  ~HighSpeed() override = default;

  void SetSpeed(GPIO_TypeDef *gpio, uint8_t pin, uint8_t speed) noexcept override;

};

}