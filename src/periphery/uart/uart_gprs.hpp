//
// Created by claiff on 8/15/21.
//

#pragma once

#include "main/stm32f407xx.h"
#include "periphery/types/ircc.hpp"
#include "periphery/types/periphery_init.h"
#include "devices/gps/gps_nmea.hpp"

namespace kvadro::periphery::uart
{

  class UART_GPRS final
  {
  public:
	UART_GPRS( USART_TypeDef *uart, kvadro::periphery::types::IRCC_Ptr const& rcc, std::shared_ptr<kvadro::device::gps::GPS_NMEA> const& gps );
	static UART_GPRS *mInstance;
	std::shared_ptr<kvadro::device::gps::GPS_NMEA> mGps;
  private:
	void InitPeriphery();
	void InitUART();
	uint32_t GetBRR( uint32_t baud_rate );

	USART_TypeDef *mUart;
	types::IRCC_Ptr mRcc;
	types::PeripheryInitPtr mPeripheryInit;
  };
}

