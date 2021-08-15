//
// Created by claiff on 8/15/21.
//

#pragma once

#include "../../main/stm32f407xx.h"
#include "../types/ircc.hpp"
#include "../types/periphery_init.h"
namespace kvadro::periphery::uart
{
  class UART_GPRS final
  {
  public:
	UART_GPRS( USART_TypeDef *uart, kvadro::periphery::interface::IRCC_Ptr const& rcc );
  private:
	void InitPeriphery();
	void InitUART();

	USART_TypeDef *mUart;
	interface::IRCC_Ptr mRcc;
	interface::PeripheryInitPtr mPeripheryInit;

  };
}

