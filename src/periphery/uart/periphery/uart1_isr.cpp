//
// Created by claiff on 6/13/21.
//
#include "uart1_isr.hpp"
#include "../../gpio/modes/alternative_mode.hpp"
#include "../../gpio/modes/input_mode.hpp"
#include "../../gpio/output_type/open_drain.hpp"
#include "../../gpio/speed/very_high_speed.hpp"
#include "../../gpio/pull/pull_up.hpp"
#include "../../gpio/pull/no_pull.hpp"

namespace kvadro::periphery::uart
{

  UART1_ISR::UART1_ISR(interface::IRCC_Ptr const& rcc)
    : mRcc(rcc)
{}

void UART1_ISR::InitPeriphery() const noexcept
{
  mRcc->SetGpioAClock();
  //TODO enum class uint16_t намутить приведение
  auto pins = static_cast<uint16_t>(interface::gpio::GPIO_PIN::PIN9);
//  mGpioInit.SetGpio(GPIOA,
//                    pins,
//                    std::make_shared<gpio::mode::AlternativeMode>(),
//                    std::make_shared<gpio::output_type::OpenDrainType>(),
//                    std::make_shared<gpio::pull::PullUp>(),
//                    std::make_shared<gpio::speed::VeryHighSpeed>(),
//                    std::make_shared<gpio::alternative_func::AlternativeFunction>(interface::FUNC_BITS_UART));
  pins = static_cast<uint16_t>(interface::gpio::GPIO_PIN::PIN10);
  mGpioInit.SetGpio(GPIOA,
					pins,
					std::make_shared<gpio::mode::InputMode>(),
					std::make_shared<gpio::output_type::OpenDrainType>(),
					std::make_shared<gpio::pull::PullNo>(),
					std::make_shared<gpio::speed::VeryHighSpeed>(),
					std::make_shared<gpio::alternative_func::AlternativeFunction>(interface::FUNC_BITS_SYS));
}

}