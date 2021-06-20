//
// Created by claiff on 6/13/21.
//

#include "input_mode.hpp"

namespace kvadro::periphery::gpio::mode
{

void InputMode::SetMode(GPIO_TypeDef *gpio, uint16_t pin) noexcept
{
  static const int INPUT_MODE = 0x00;
  mMode = INPUT_MODE;
  GpioMode::SetMode(gpio, pin);
}

}