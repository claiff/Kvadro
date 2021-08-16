//
// Created by claiff on 8/15/21.
//

#pragma once

#include "main/stm32f407xx.h"
#include "periphery/types/ircc.hpp"
#include "periphery/types/periphery_init.h"

namespace kvadro::periphery::uart
{
  class UART_GPRS final
  {
  public:
	UART_GPRS( USART_TypeDef *uart, kvadro::periphery::types::IRCC_Ptr const& rcc );
  private:
	void InitPeriphery();
	void InitUART();

	USART_TypeDef *mUart;
	types::IRCC_Ptr mRcc;
	types::PeripheryInitPtr mPeripheryInit;

  };
}

