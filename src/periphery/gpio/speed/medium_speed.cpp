//
// Created by claiff on 6/13/21.
//

#include "medium_speed.hpp"

namespace kvadro::periphery::gpio::speed
{

void MediumSpeed::SetSpeed(GPIO_TypeDef *gpio, uint8_t pin, uint8_t speed) noexcept
{
  static const int MEDIUM_SPEED = 0x01;
  mSpeed = MEDIUM_SPEED;
  GpioSpeed::SetSpeed(gpio, pin, mSpeed);
}

}