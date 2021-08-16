//
// Created by claiff on 6/13/21.
//

#pragma once

#include "periphery/types/ii2c.hpp"
#include "periphery/types/periphery_init.h"
#include "periphery/types/ircc.hpp"

namespace kvadro::periphery::i2c
{
  class I2cMaxSpeed : public types::II2C
  {
  public:
	explicit I2cMaxSpeed( I2C_TypeDef *i2c, kvadro::periphery::types::IRCC_Ptr rcc );
	~I2cMaxSpeed() override = default;

	void InitI2C() const noexcept;
	void ReadData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const noexcept override;
	void WriteData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const noexcept override;

  private:
	I2C_TypeDef *mI2c;
	types::IRCC_Ptr mRcc;
	types::PeripheryInitPtr mPeripheryInit;
  };

}