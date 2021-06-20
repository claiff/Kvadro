//
// Created by claiff on 6/13/21.
//

#include "high_speed.hpp"

namespace kvadro::periphery::gpio::speed
{

void HighSpeed::SetSpeed(GPIO_TypeDef *gpio, uint8_t pin, uint8_t speed) noexcept
{
  const int HIGH_SPEED = 0x02;
  mSpeed = HIGH_SPEED;
  GpioSpeed::SetSpeed(gpio, pin, mSpeed);
}

}