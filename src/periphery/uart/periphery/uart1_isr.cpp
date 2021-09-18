//
// Created by claiff on 6/13/21.
//
#include "uart1_isr.hpp"
#include "periphery/gpio/modes/alternative_mode.hpp"
#include "periphery/gpio/modes/input_mode.hpp"
#include "periphery/gpio/output_type/push_pull.hpp"
#include "periphery/gpio/speed/very_high_speed.hpp"
#include "periphery/gpio/pull/pull_up.hpp"
#include "periphery/gpio/pull/no_pull.hpp"

namespace kvadro::periphery::uart
{

  UART1_ISR::UART1_ISR( types::IRCC_Ptr const& rcc ) :
	  mRcc( rcc )
  {
  }

  void UART1_ISR::InitPeriphery() const noexcept
  {
	mRcc->SetGpioAClock();
	//TODO enum class uint16_t намутить приведение
	auto pins = static_cast<uint16_t>(types::gpio::GPIO_PIN::PIN9);
	mGpioInit.SetGpio( GPIOA,
					   pins,
					   std::make_shared<gpio::mode::AlternativeMode>(),
					   std::make_shared<gpio::output_type::PushPullType>(),
					   std::make_shared<gpio::pull::PullUp>(),
					   std::make_shared<gpio::speed::VeryHighSpeed>(),
					   std::make_shared<gpio::alternative_func::AlternativeFunction>( types::FUNC_BITS_UART ) );
	pins = static_cast<uint16_t>(types::gpio::GPIO_PIN::PIN10);
	mGpioInit.SetGpio( GPIOA,
					   pins,
					   std::make_shared<gpio::mode::AlternativeMode>(),
					   std::make_shared<gpio::output_type::PushPullType>(),
					   std::make_shared<gpio::pull::PullNo>(),
					   std::make_shared<gpio::speed::VeryHighSpeed>(),
					   std::make_shared<gpio::alternative_func::AlternativeFunction>( types::FUNC_BITS_UART ) );
  }

}