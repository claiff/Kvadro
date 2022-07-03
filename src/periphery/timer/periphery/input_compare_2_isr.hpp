//
// Created by claiff on 18.06.22.
//

#pragma once

#include "periphery/gpio/gpio_init.hpp"
#include "periphery/types/ircc.hpp"
#include "periphery/types/periphery_init.h"

namespace periphery::timer
{
	class InputCompare2Isr: public types::PeripheryInit
	{
	public:
		explicit InputCompare2Isr( types::IRCC_Ptr const& rcc );
		~InputCompare2Isr() override = default;

		void InitPeriphery() const noexcept override;

	private:
		types::IRCC_Ptr mRcc;
		gpio::GpioInit mGpioInit;
	};
}
