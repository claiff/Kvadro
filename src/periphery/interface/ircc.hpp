//
// Created by claiff on 6/12/21.
//

#pragma once

#include "memory"
#include "../../main/stm32f407xx.h"

namespace kvadro::periphery::interface
{

class IRCC
{
public:
  virtual ~IRCC() = default;

  virtual void SetDefaultRCC() const noexcept = 0;
  virtual void SetI2cClock() const noexcept
  {

  }
  virtual void SetGpioBClock() const noexcept
  {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
  }
  virtual void SetGpioCClock() const noexcept
  {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
  }
  virtual void SetGpioAClock() const noexcept
  {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  }
  virtual void SetGpioI2C1Clock() const noexcept
  {
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
  }
  virtual void SetGpioI2C2Clock() const noexcept
  {
    RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
  }
  virtual void SetGpioI2C3Clock() const noexcept
  {
    RCC->APB1ENR |= RCC_APB1ENR_I2C3EN;
  }
};
using IRCC_Ptr = std::shared_ptr<IRCC>;
}


