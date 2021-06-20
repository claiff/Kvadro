//
// Created by claiff on 6/13/21.
//

#pragma once

#include "../../interface/gpio/gpio_mode.hpp"

namespace kvadro::periphery::gpio::mode
{

class InputMode : public periphery::interface::gpio::GpioMode
{
public:
  InputMode() = default;
  ~InputMode() override = default;

  void SetMode(GPIO_TypeDef *gpio, uint16_t pin) noexcept override;
};

}