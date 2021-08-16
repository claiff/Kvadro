//
// Created by claiff on 6/10/21.
//

#include "iaccel.hpp"

namespace kvadro::device::accel
{
  IAccel::IAccel(periphery::types::I2CPtr i2c):mI2c(std::move(i2c)){}

void IAccel::ReadData(uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count) const noexcept
{
  mI2c->ReadData(address, reg, buffer, count );
}
void IAccel::WriteData(uint8_t address, uint8_t reg, uint8_t *buffer, uint8_t count) const noexcept
{
  mI2c->WriteData(address, reg, buffer, count);
}

}