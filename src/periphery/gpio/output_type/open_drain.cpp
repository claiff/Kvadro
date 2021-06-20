//
// Created by claiff on 6/13/21.
//

#include "open_drain.hpp"

namespace kvadro::periphery::gpio::output_type
{

void OpenDrainType::SetOutputType(GPIO_TypeDef *gpio, uint8_t pin) noexcept
{
  static const int OPEN_DRAIN_TYPE = 0x01;
  mOutputType = OPEN_DRAIN_TYPE;
  GpioOutputType::SetOutputType(gpio, pin);
}
}