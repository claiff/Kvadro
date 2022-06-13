//
// Created by claiff on 6/13/21.
//
#pragma once

#include "periphery/types/gpio/gpio_pull.hpp"

namespace periphery::gpio::pull
{

  class PullUp : public periphery::types::gpio::GpioPull
{
public:
  PullUp() = default;
  ~PullUp() override = default;

  void SetPull(GPIO_TypeDef *gpio, uint8_t pin) noexcept override;

};

}