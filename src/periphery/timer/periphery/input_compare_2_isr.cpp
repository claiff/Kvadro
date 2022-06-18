//
// Created by claiff on 18.06.22.
//

#include "input_compare_2_isr.hpp"
#include "periphery/gpio/modes/alternative_mode.hpp"
#include "periphery/gpio/modes/input_mode.hpp"
#include "periphery/gpio/output_type/push_pull.hpp"
#include "periphery/gpio/speed/low_speed.hpp"
#include "periphery/gpio/pull/no_pull.hpp"

namespace periphery::timer
{

	InputCompare2Isr::InputCompare2Isr( types::IRCC_Ptr const& rcc )
			: mRcc( rcc )
	{

	}
//TODO shared_ptr
	void InputCompare2Isr::InitPeriphery() const noexcept
	{
		mRcc->SetGpioEClock();
		//TODO enum class uint16_t намутить приведение
		auto pins = static_cast<uint16_t>(types::gpio::GPIO_PIN::PIN9);
		mGpioInit.SetGpio(GPIOE,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::PushPullType (),
						  new gpio::pull::PullNo (),
						  new gpio::speed::LowSpeed (),
						  new gpio::alternative_func::AlternativeFunction ( types::FUNC_BITS_TIM_IC ));
	}
}
