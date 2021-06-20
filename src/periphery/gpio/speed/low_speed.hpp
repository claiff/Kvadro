//
// Created by claiff on 6/13/21.
//
#include "../../interface/gpio/gpio_speed.hpp"

#pragma once

namespace kvadro::periphery::gpio::speed
{

class LowSpeed : public periphery::interface::gpio::GpioSpeed
{
public:
  LowSpeed() = default;
  ~LowSpeed() override = default;

  void SetSpeed(GPIO_TypeDef *gpio, uint8_t pin, uint8_t speed) noexcept override;
};

}