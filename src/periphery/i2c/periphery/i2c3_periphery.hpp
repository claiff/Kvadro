//
// Created by claiff on 6/13/21.
//

#pragma once

#include "periphery/gpio/gpio_init.hpp"
#include "periphery/types/ircc.hpp"
#include "periphery/types/periphery_init.h"

namespace kvadro::periphery::i2c
{

  class I2C3Periphery : public types::PeripheryInit
{
public:
  explicit I2C3Periphery(types::IRCC_Ptr rcc);
  ~I2C3Periphery() override = default;

  void InitPeriphery() const noexcept override;

private:
  types::IRCC_Ptr mRcc;
};

}