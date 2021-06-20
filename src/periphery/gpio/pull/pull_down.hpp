//
// Created by claiff on 6/13/21.
//
#include "../../interface/gpio/gpio_pull.hpp"

#pragma once

namespace kvadro::periphery::gpio::pull
{

class PullDown : public periphery::interface::gpio::GpioPull
{
public:
  PullDown() = default;
  ~PullDown() override = default;

  void SetPull(GPIO_TypeDef *gpio, uint8_t pin) noexcept override;
};

}