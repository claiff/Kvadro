//
// Created by claiff on 8/15/21.
//
#include "uart_gprs.hpp"
#include "periphery/uart1_isr.hpp"

namespace kvadro::periphery::uart
{
  UART_GPRS::UART_GPRS( USART_TypeDef *uart, kvadro::periphery::types::IRCC_Ptr const& rcc ) :
	  mUart( uart ),
	  mRcc( rcc )
  {
	InitPeriphery();
	InitUART();
  }

  void UART_GPRS::InitPeriphery()
  {
	if( mUart == USART1 )
	{
	  mPeripheryInit = std::make_shared<UART1_ISR>( mRcc );
	  mRcc->SetGpioUart1Clock();
	}
  }

  void UART_GPRS::InitUART()
  {
	mPeripheryInit->InitPeriphery();

	mUart->CR1 |= USART_CR1_RXNEIE;
	mUart->CR1 |= USART_CR1_RE;
	mUart->CR1 |= USART_CR1_UE;

	NVIC_EnableIRQ( USART1_IRQn );
  }

  extern "C" void USART1_IRQHandler()
  {
	bool begin;
	uint8_t data = USART1->DR;
	if( data == '$' )
	  begin = true;
  }

}