//
// Created by claiff on 6/13/21.
//

#pragma once

#include "../interface/ii2c.hpp"
#include "../interface/periphery_init.h"
#include "../interface/ircc.hpp"

namespace kvadro::periphery::i2c
{

class I2cMaxSpeed : public interface::II2C
{
public:
  explicit I2cMaxSpeed(I2C_TypeDef *i2c, kvadro::periphery::interface::IRCC_Ptr rcc);
  ~I2cMaxSpeed() override = default;

  void InitI2C() const noexcept;
  void ReadData(uint8_t address, uint8_t reg, uint8_t *buffer,
                uint8_t count) const noexcept override;
  void WriteData(uint8_t address, uint8_t reg, uint8_t *buffer,
                 uint8_t count) const noexcept override;

private:
  I2C_TypeDef* mI2c;
  interface::IRCC_Ptr mRcc;
  interface::PeripheryInitPtr mPeripheryInit;
};

}