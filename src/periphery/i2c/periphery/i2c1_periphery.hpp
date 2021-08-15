//
// Created by claiff on 6/13/21.
//

#pragma once

#include "../../gpio/gpio_init.hpp"
#include "../../types/ircc.hpp"
#include "../../types/periphery_init.h"

namespace kvadro::periphery::i2c
{

class I2C1Periphery : public interface::PeripheryInit
{
public:
  explicit I2C1Periphery(interface::IRCC_Ptr rcc);
  ~I2C1Periphery() override = default;

  void InitPeriphery() const noexcept override;

private:
  interface::IRCC_Ptr mRcc;
  gpio::GpioInit mGpioInit;
};

}