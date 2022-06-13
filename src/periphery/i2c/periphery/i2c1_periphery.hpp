//
// Created by claiff on 6/13/21.
//

#pragma once

#include "periphery/gpio/gpio_init.hpp"
#include "periphery/types/ircc.hpp"
#include "periphery/types/periphery_init.h"

namespace periphery::i2c
{

  class I2C1Periphery : public types::PeripheryInit
{
public:
  explicit I2C1Periphery(types::IRCC_Ptr rcc);
  ~I2C1Periphery() override = default;

  void InitPeriphery() const noexcept override;

private:
  types::IRCC_Ptr mRcc;
  gpio::GpioInit mGpioInit;
};

}