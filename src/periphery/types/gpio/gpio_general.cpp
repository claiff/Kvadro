//
// Created by claiff on 8/15/21.
//
#include "gpio_general.hpp"

namespace kvadro::periphery::interface::gpio
{
  bool GpioGeneral::IsActivePin( uint16_t pin, uint8_t chosen_pin )
  {
	return ( pin & ( 1 << chosen_pin ) ) == ( 1 << chosen_pin );
  }
}