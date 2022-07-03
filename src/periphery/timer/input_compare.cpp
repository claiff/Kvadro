//
// Created by claiff on 18.06.22.
//

#include "input_compare.hpp"
#include "periphery/input_compare_2_isr.hpp"

namespace periphery::timer
{
	InputCompare* InputCompare::mInstance = nullptr;

	InputCompare::InputCompare( TIM_TypeDef* timer, types::IRCC_Ptr const& rcc,
								device::RadioControl const& data_sender )
			: mTimer( timer )
			, mRcc( rcc )
			, mDataSender( data_sender )
	{
		InitPeriphery();
		InitTimer();
		mInstance = this;
	}

	extern "C" void TIM1_CC_IRQHandler()
	{
		uint32_t status = TIM1->SR;
		if((status & TIM_SR_CC1IF) == TIM_SR_CC1IF)
		{
			TIM1->CNT = 0;
			TIM1->CCR1 = 0;
			TIM1->CCR2 = 0;
			TIM1->SR &=~ TIM_SR_CC1IF;
			return;
		}
		if((status & TIM_SR_CC2IF) == TIM_SR_CC2IF)
		{
			TIM1->SR &=~ TIM_SR_CC2IF;
			volatile uint32_t temp = TIM1->CCR2;
			InputCompare::mInstance->mDataSender.AddData(temp);
		}
	}

	void InputCompare::InitPeriphery()
	{
		if( mTimer == TIM1)
		{
			mPeripheryInit = new InputCompare2Isr( mRcc );
			mRcc->SetGpioTim1Clock();
		}
	}

	void InputCompare::InitTimer()
	{
		mPeripheryInit->InitPeriphery();
		//0x06
		mTimer->DIER |= TIM_DIER_CC1IE;
		mTimer->DIER |= TIM_DIER_CC2IE;

		//0x22
		mTimer->CCMR1 |= TIM_CCMR1_CC1S_0;
		mTimer->CCMR1 |= TIM_CCMR1_IC1F_1; //IC1F = 0b10
		mTimer->CCMR1 |= TIM_CCMR1_CC2S_1;  //0b10

		//0x31
		mTimer->CCER |= TIM_CCER_CC1E;
		mTimer->CCER |= TIM_CCER_CC2E;
		mTimer->CCER |= TIM_CCER_CC2P;

		mTimer->PSC = mRcc->GetClock() * 10;
		mTimer->ARR = 0xFFFF;

		mTimer->CR1 |= TIM_CR1_CEN;
		NVIC_EnableIRQ( TIM1_CC_IRQn );
	}
}