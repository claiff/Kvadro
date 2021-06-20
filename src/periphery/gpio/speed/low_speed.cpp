//
// Created by claiff on 6/13/21.
//

#include "low_speed.hpp"

namespace kvadro::periphery::gpio::speed
{

void LowSpeed::SetSpeed(GPIO_TypeDef *gpio, uint8_t pin, uint8_t speed) noexcept
{
  static const int LOW_SPEED = 0x00;
  mSpeed = LOW_SPEED;
  GpioSpeed::SetSpeed(gpio, pin, mSpeed);
}

}