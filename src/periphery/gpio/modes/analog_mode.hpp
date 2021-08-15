//
// Created by claiff on 6/13/21.
//
#include "../../types/gpio/gpio_mode.hpp"

#pragma once

namespace kvadro::periphery::gpio::mode
{

class AnalogMode : public periphery::interface::gpio::GpioMode
{
public:
  AnalogMode() = default;
  ~AnalogMode() override = default;

  void SetMode(GPIO_TypeDef *gpio, uint16_t pin) noexcept override;
};

}