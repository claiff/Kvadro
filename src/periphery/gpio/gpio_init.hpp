//
// Created by claiff on 6/13/21.
//
#pragma once

#include "main/stm32f407xx.h"
#include "periphery/types/gpio/gpio_mode.hpp"
#include "periphery/types/gpio/gpio_output_type.hpp"
#include "periphery/types/gpio/gpio_pull.hpp"
#include "periphery/types/gpio/gpio_speed.hpp"
#include "periphery/gpio/alternative_function/alternative_function.hpp"

namespace kvadro::periphery::gpio
{

  class GpioInit
  {
  public:
	GpioInit() = default;
	virtual ~GpioInit() = default;

	void SetGpio( GPIO_TypeDef *gpio,
				  uint16_t group_pins,
				  types::gpio::GPIO_ModePtr const& gpio_mode,
				  types::gpio::GpioOutputTypePtr const& output_type,
				  types::gpio::GpioPullPtr const& pull,
				  types::gpio::GpioSpeedPtr const& speed,
				  alternative_func::AlternativeFunctionPtr const& func ) const noexcept;
  };

}