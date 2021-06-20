//
// Created by claiff on 6/13/21.
//

#include "very_high_speed.hpp"

namespace kvadro::periphery::gpio::speed
{

void VeryHighSpeed::SetSpeed(GPIO_TypeDef *gpio, uint8_t pin, uint8_t speed) noexcept
{
  static const int VERY_HIGH_SPEED = 0x03;
  mSpeed = VERY_HIGH_SPEED;
  GpioSpeed::SetSpeed(gpio, pin, mSpeed);
}

}