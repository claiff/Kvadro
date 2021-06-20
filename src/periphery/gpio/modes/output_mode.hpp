//
// Created by claiff on 6/13/21.
//
#include "../../interface/gpio/gpio_mode.hpp"

#pragma once

namespace kvadro::periphery::gpio::mode
{

class OutputMode : public periphery::interface::gpio::GpioMode
{
public:
  OutputMode() = default;
  ~OutputMode() override = default;

  void SetMode(GPIO_TypeDef *gpio, uint16_t pin) noexcept override;
};

}