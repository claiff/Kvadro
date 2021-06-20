//
// Created by claiff on 6/13/21.
//
#include "gpio_init.hpp"


namespace kvadro::periphery::gpio
{

void GpioInit::SetGpio(GPIO_TypeDef *gpio, uint16_t pin,
                       const interface::gpio::GPIO_ModePtr &gpio_mode,
                       const interface::gpio::GpioOutputTypePtr &output_type,
                       const interface::gpio::GpioPullPtr &pull,
                       const interface::gpio::GpioSpeedPtr &speed,
                       alternative_func::AlternativeFunctionPtr const& func) const noexcept
{
  gpio_mode->SetMode(gpio, pin);
  output_type->SetOutputType(gpio, pin);
  pull->SetPull(gpio, pin);
  speed->SetSpeed(gpio, pin, 0);
  func->SetFunction(gpio, pin);
}
}


