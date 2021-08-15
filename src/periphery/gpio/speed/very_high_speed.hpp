//
// Created by claiff on 6/13/21.
//
#include "../../types/gpio/gpio_speed.hpp"

#pragma once

namespace kvadro::periphery::gpio::speed
{

class VeryHighSpeed : public periphery::interface::gpio::GpioSpeed
{
public:
  VeryHighSpeed() = default;
  ~VeryHighSpeed() override = default;

  void SetSpeed(GPIO_TypeDef *gpio, uint8_t pin, uint8_t speed) noexcept override;

};

}