//
// Created by claiff on 6/13/21.
//
#include "i2c3_periphery.hpp"
#include "periphery/gpio/modes/alternative_mode.hpp"
#include "periphery/gpio/output_type/push_pull.hpp"
#include "periphery/gpio/speed/very_high_speed.hpp"
#include "periphery/gpio/pull/pull_up.hpp"

namespace periphery::i2c
{

	I2C3Periphery::I2C3Periphery( types::IRCC_Ptr rcc )
			: mRcc( std::move( rcc ))
	{
	}


	void I2C3Periphery::InitPeriphery() const noexcept
	{
		gpio::GpioInit gpio_init;
		mRcc->SetGpioAClock();
		mRcc->SetGpioCClock();
		//TODO enum class uint16_t
		auto pins = static_cast<uint16_t>(types::gpio::GPIO_PIN::PIN8);
		gpio_init.SetGpio(GPIOA,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::PushPullType(),
						  new gpio::pull::PullUp(),
						  new gpio::speed::VeryHighSpeed(),
						  new gpio::alternative_func::AlternativeFunction(
								  types::FUNC_BITS_I2C ));

		pins = static_cast<uint16_t>(types::gpio::GPIO_PIN::PIN9);
		gpio_init.SetGpio(GPIOC,
						  pins,
						  new gpio::mode::AlternativeMode(),
						  new gpio::output_type::PushPullType(),
						  new gpio::pull::PullUp(),
						  new gpio::speed::VeryHighSpeed(),
						  new gpio::alternative_func::AlternativeFunction(
								  types::FUNC_BITS_I2C ));
	}

}