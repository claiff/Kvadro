//
// Created by claiff on 6/13/21.
//
#include "i2c1_periphery.hpp"
#include "../../gpio/modes/alternative_mode.hpp"
#include "../../gpio/output_type/open_drain.hpp"
#include "../../gpio/speed/very_high_speed.hpp"
#include "../../gpio/pull/pull_up.hpp"

#include <utility>

namespace kvadro::periphery::i2c
{

I2C1Periphery::I2C1Periphery(interface::IRCC_Ptr rcc)
    : mRcc(std::move(rcc))
{}

void I2C1Periphery::InitPeriphery() const noexcept
{
  mRcc->SetGpioBClock();
  //TODO enum class uint16_t
  auto pins = static_cast<uint16_t>(interface::gpio::GPIO_PIN::PIN6) + static_cast<uint16_t>(interface::gpio::GPIO_PIN::PIN7);
  mGpioInit.SetGpio(GPIOB,
                    pins,
                    std::make_shared<gpio::mode::AlternativeMode>(),
                    std::make_shared<gpio::output_type::OpenDrainType>(),
                    std::make_shared<gpio::pull::PullUp>(),
                    std::make_shared<gpio::speed::VeryHighSpeed>(),
                    std::make_shared<gpio::alternative_func::AlternativeFunction>(interface::FUNC_BITS_I2C));
}

}