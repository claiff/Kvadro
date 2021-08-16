//
// Created by claiff on 8/16/21.
//

#include "ircc.hpp"

namespace kvadro::periphery::types
{
  void IRCC::SetGpioBClock() const noexcept
  {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
  }
  void IRCC::SetGpioCClock() const noexcept
  {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
  }
  void IRCC::SetGpioAClock() const noexcept
  {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  }
  void IRCC::SetGpioI2C1Clock() const noexcept
  {
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
  }
  void IRCC::SetGpioI2C2Clock() const noexcept
  {
	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
  }
  void IRCC::SetGpioI2C3Clock() const noexcept
  {
	RCC->APB1ENR |= RCC_APB1ENR_I2C3EN;
  }
  void IRCC::SetGpioUart1Clock() const noexcept
  {
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
  }
}