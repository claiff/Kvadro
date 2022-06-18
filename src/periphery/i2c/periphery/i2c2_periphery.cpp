//
// Created by claiff on 6/13/21.
//
#include "i2c2_periphery.hpp"

#include "periphery/gpio/modes/alternative_mode.hpp"
#include "periphery/gpio/output_type/push_pull.hpp"
#include "periphery/gpio/speed/very_high_speed.hpp"
#include "periphery/gpio/pull/pull_up.hpp"

namespace periphery::i2c
{

	I2C2Periphery::I2C2Periphery( types::IRCC_Ptr rcc )
			: mRcc( std::move( rcc ))
	{
	}

	void I2C2Periphery::InitPeriphery() const noexcept
	{
		mRcc->SetGpioBClock();
		//TODO enum class uint16_t
		auto pins = static_cast<uint16_t>(types::gpio::GPIO_PIN::PIN10) +
					static_cast<uint16_t>(types::gpio::GPIO_PIN::PIN11);
		mGpioInit.SetGpio(GPIOB,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::PushPullType(),
						  new gpio::pull::PullUp(),
						  new gpio::speed::VeryHighSpeed(),
						  new gpio::alternative_func::AlternativeFunction( types::FUNC_BITS_I2C ));
	}

}