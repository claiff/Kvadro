//
// Created by claiff on 18.06.22.
//

#pragma once

#include "main/stm32f407xx.h"
#include "periphery/types/ircc.hpp"
#include "devices/radio_control/radio_control.hpp"
#include "periphery/types/periphery_init.h"

namespace periphery::timer
{
	class InputCompare final
	{
	public:
		InputCompare( TIM_TypeDef* timer, periphery::types::IRCC_Ptr const& rcc,
					  device::RadioControl const& data_sender );
		~InputCompare() = default;

		static InputCompare* mInstance;
		device::RadioControl mDataSender;
	private:
		void InitPeriphery();
		void InitTimer();

		TIM_TypeDef* mTimer;
		types::IRCC_Ptr mRcc;
		types::PeripheryInitPtr mPeripheryInit;
	};

} // periphery
