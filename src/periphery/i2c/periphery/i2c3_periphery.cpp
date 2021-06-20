//
// Created by claiff on 6/13/21.
//
#include "i2c3_periphery.hpp"
#include "../../gpio/modes/alternative_mode.hpp"
#include "../../gpio/output_type/push_pull.hpp"
#include "../../gpio/speed/very_high_speed.hpp"
#include "../../gpio/pull/pull_up.hpp"

namespace kvadro::periphery::i2c
{

I2C3Periphery::I2C3Periphery(interface::IRCC_Ptr rcc)
    : mRcc(std::move(rcc)) {}


void I2C3Periphery::InitPeriphery() const noexcept
{
  gpio::GpioInit gpio_init;
  mRcc->SetGpioAClock();
  mRcc->SetGpioCClock();
  //TODO enum class uint16_t
  auto pins = static_cast<uint16_t>(interface::gpio::GPIO_PIN::PIN8);
  gpio_init.SetGpio(GPIOA,
                    pins,
                    std::make_shared<gpio::mode::AlternativeMode>(),
                    std::make_shared<gpio::output_type::PushPullType>(),
                    std::make_shared<gpio::pull::PullUp>(),
                    std::make_shared<gpio::speed::VeryHighSpeed>(),
                    std::make_shared<gpio::alternative_func::AlternativeFunction>(
                          interface::FUNC_BITS_I2C));

  pins = static_cast<uint16_t>(interface::gpio::GPIO_PIN::PIN9);
  gpio_init.SetGpio(GPIOC,
                    pins,
                    std::make_shared<gpio::mode::AlternativeMode>(),
                    std::make_shared<gpio::output_type::PushPullType>(),
                    std::make_shared<gpio::pull::PullUp>(),
                    std::make_shared<gpio::speed::VeryHighSpeed>(),
                    std::make_shared<gpio::alternative_func::AlternativeFunction>(
                          interface::FUNC_BITS_I2C));
}

}