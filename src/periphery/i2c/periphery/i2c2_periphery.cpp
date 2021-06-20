//
// Created by claiff on 6/13/21.
//
#include "i2c2_periphery.hpp"

#include "../../gpio/modes/alternative_mode.hpp"
#include "../../gpio/output_type/push_pull.hpp"
#include "../../gpio/speed/very_high_speed.hpp"
#include "../../gpio/pull/pull_up.hpp"

namespace kvadro::periphery::i2c
{

I2C2Periphery::I2C2Periphery(interface::IRCC_Ptr rcc)
    : mRcc(std::move(rcc)) {}

void I2C2Periphery::InitPeriphery() const noexcept
{
  mRcc->SetGpioBClock();
  //TODO enum class uint16_t
  auto pins = static_cast<uint16_t>(interface::gpio::GPIO_PIN::PIN10) + static_cast<uint16_t>(interface::gpio::GPIO_PIN::PIN11);
  mGpioInit.SetGpio(GPIOB,
                    pins,
                    std::make_shared<gpio::mode::AlternativeMode>(),
                    std::make_shared<gpio::output_type::PushPullType>(),
                    std::make_shared<gpio::pull::PullUp>(),
                    std::make_shared<gpio::speed::VeryHighSpeed>(),
                    std::make_shared<gpio::alternative_func::AlternativeFunction>(interface::FUNC_BITS_I2C));
}

}