//
// Created by claiff on 6/13/21.
//
#include "gpio_init.hpp"

namespace kvadro::periphery::gpio
{

  void GpioInit::SetGpio( GPIO_TypeDef *gpio,
						  uint16_t group_pins,
						  const types::gpio::GPIO_ModePtr& gpio_mode,
						  const types::gpio::GpioOutputTypePtr& output_type,
						  const types::gpio::GpioPullPtr& pull,
						  const types::gpio::GpioSpeedPtr& speed,
						  alternative_func::AlternativeFunctionPtr const& func ) const noexcept
  {
	gpio_mode->SetMode( gpio, group_pins );
	output_type->SetOutputType( gpio, group_pins );
	pull->SetPull( gpio, group_pins );
	speed->SetSpeed( gpio, group_pins, 0 );
	func->SetFunction( gpio, group_pins );
  }
}


