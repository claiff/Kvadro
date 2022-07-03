//
// Created by claiff on 8/15/21.
//

#pragma once

#include "main/stm32f407xx.h"
#include "periphery/types/ircc.hpp"
#include "periphery/types/periphery_init.h"
#include "devices/gps/gps_nmea.hpp"

namespace periphery::uart
{
  class UART_GPRS final
  {
  public:
	UART_GPRS( USART_TypeDef *uart, periphery::types::IRCC_Ptr const& rcc, device::gps::headers::types::IGpsHeaderPtr gps  );
	  static UART_GPRS* mInstance;
	  device::gps::headers::types::IGpsHeaderPtr mGps;
  private:
	void InitPeriphery();
	void InitUART();
	uint32_t GetBRR( uint32_t baud_rate );

	USART_TypeDef *mUart;
	types::IRCC_Ptr mRcc;
	types::PeripheryInitPtr mPeripheryInit;
  };
}

