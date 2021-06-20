//
// Created by claiff on 6/13/21.
//

#include "alternative_mode.hpp"
namespace kvadro::periphery::gpio::mode
{


void AlternativeMode::SetMode(GPIO_TypeDef *gpio, uint16_t pin) noexcept
{
  const int ALTERNATIVE_MODE = 0x02;
  mMode = ALTERNATIVE_MODE;
  GpioMode::SetMode(gpio, pin);
}

}