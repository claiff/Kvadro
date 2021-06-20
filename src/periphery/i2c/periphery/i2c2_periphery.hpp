//
// Created by claiff on 6/13/21.
//

#pragma once

#include "../../gpio/gpio_init.hpp"
#include "../../interface/ircc.hpp"
#include "../../interface/periphery_init.h"

namespace kvadro::periphery::i2c
{

class I2C2Periphery : public interface::PeripheryInit
{
public:
  explicit I2C2Periphery(interface::IRCC_Ptr rcc);
  ~I2C2Periphery() override = default;

  void InitPeriphery() const noexcept override;

private:
  interface::IRCC_Ptr mRcc;
  gpio::GpioInit mGpioInit;
};

}