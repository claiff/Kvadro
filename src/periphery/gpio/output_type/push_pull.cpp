//
// Created by claiff on 6/13/21.
//

#include "push_pull.hpp"

namespace kvadro::periphery::gpio::output_type
{

void PushPullType::SetOutputType(GPIO_TypeDef *gpio, uint8_t pin) noexcept
{
  const int PUSH_PULL_TYPE = 0x00;
  mOutputType = PUSH_PULL_TYPE;
  GpioOutputType::SetOutputType(gpio, pin);
}

}