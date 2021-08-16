//
// Created by claiff on 6/10/21.
//
/*
@startuml
abstract class IAccel
{
 *-- I2CPtr i2c
 *-- SdCard sd_card
 -abstract ReadSettings()
}
@enduml
*/
#pragma once

#include "periphery/types/ii2c.hpp"

enum class ACCEL_MODE
{
  LOW, MEDDIUM, HIGH
};

namespace kvadro::device::accel
{

  class IAccel
  {
  public:
	explicit IAccel( periphery::types::I2CPtr i2c );
	[[nodiscard]] virtual bool IsAccelOnline() const noexcept = 0;
	[[nodiscard]] virtual bool SetAccelMode( ACCEL_MODE mode ) const noexcept = 0;
  protected:
	void ReadData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const noexcept;
	void WriteData( uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count ) const noexcept;
  private:
	periphery::types::I2CPtr mI2c;
  };

  using IAccelPtr = std::shared_ptr<IAccel>;
}

