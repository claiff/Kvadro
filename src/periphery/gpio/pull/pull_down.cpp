//
// Created by claiff on 6/13/21.
//

#include "pull_down.hpp"

namespace periphery::gpio::pull
{

void PullDown::SetPull(GPIO_TypeDef *gpio, uint8_t pin) noexcept
{
  static const int PULL_DOWN = 0x02;
  mPull = PULL_DOWN;
  GpioPull::SetPull(gpio, pin);
}

}