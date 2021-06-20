//
// Created by claiff on 6/14/21.
//
#pragma once

#include "../../../main/stm32f407xx.h"
#include "memory"

namespace kvadro::periphery::interface::gpio
{
  const static uint8_t COUNT_PINS = 16;
  class GpioGeneral
  {
  protected:
    bool IsActivePin(uint16_t pin, uint8_t chosen_pin)
    {
      if((pin & (1 << chosen_pin)) == (1 << chosen_pin))
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  };
}