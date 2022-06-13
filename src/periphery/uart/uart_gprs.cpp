//
// Created by claiff on 8/15/21.
//
#include "uart_gprs.hpp"
#include "periphery/uart1_isr.hpp"

namespace periphery::uart
{
#define UART_DIV_SAMPLING16( _PCLK_, _BAUD_ )            ((uint32_t)((((uint64_t)(_PCLK_))*25U)/(4U*((uint64_t)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING16( _PCLK_, _BAUD_ )        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16( _PCLK_, _BAUD_ )        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16( _PCLK_, _BAUD_ )            ((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

  UART_GPRS *UART_GPRS::mInstance = nullptr;

  UART_GPRS::UART_GPRS( USART_TypeDef *uart, periphery::types::IRCC_Ptr const& rcc,
						device::gps::headers::types::IGpsHeaderPtr gps ) :
	  mUart( uart ),
	  mRcc( rcc ),
	  mGps( gps )
  {
	InitPeriphery();
	InitUART();
	mInstance = this;
  }

  extern "C" void USART1_IRQHandler()
  {
	UART_GPRS::mInstance->mGps->AddData( USART1->DR );
	USART1->SR &= ~USART_SR_RXNE;
  }

  //
  //Private methods
  //

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
	mUart->BRR = GetBRR( 9600 );
	NVIC_EnableIRQ( USART1_IRQn );
  }

  uint32_t UART_GPRS::GetBRR( uint32_t baud_rate )
  {
	uint32_t pclk = 16000000;
	volatile auto temp = UART_BRR_SAMPLING16( pclk, baud_rate );

	return temp;
  }

}
