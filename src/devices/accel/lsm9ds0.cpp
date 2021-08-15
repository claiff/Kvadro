//
// Created by claiff on 6/16/21.
//

#include "lsm9ds0.hpp"

namespace kvadro::device::accel
{

bool LSM9DS0::IsAccelOnline() const noexcept
{
  uint8_t data = 0;
  ReadData(ACCEL_ADDRESS, WHO_AM_I_G, &data, sizeof(data) );
  return data == WHO_AM_I_G_RET;
}

bool LSM9DS0::SetAccelMode(ACCEL_MODE mode) const noexcept
{
  SetReg1(mode);
  SetReg2(mode);
}

void LSM9DS0::SetReg1(ACCEL_MODE mode) const noexcept
{
  uint8_t reg_data = 0;
  reg_data |= (XEN | YEN | ZEN);
  reg_data |= NORMAL_MODE;

  switch (mode)
  {
  case ACCEL_MODE::LOW:
    reg_data |= CUTOFF_12_5_ODR_95;
    break;
  case ACCEL_MODE::MEDDIUM:
    reg_data |= CUTOFF_50_ODR_380;
    break;
  case ACCEL_MODE::HIGH:
    reg_data |= CUTOFF_100_ODR_760;
    break;
  }
  WriteData(ACCEL_ADDRESS, CTRL_REG1_G, &reg_data, sizeof(reg_data) );
}

void LSM9DS0::SetReg2(ACCEL_MODE mode) const noexcept
{
  uint8_t reg_data = 0;
  reg_data |= HPM_NORMAL_MODE;

  switch (mode)
  {
  case ACCEL_MODE::LOW:
    reg_data |= HPCF_LOW;
    break;
  case ACCEL_MODE::MEDDIUM:
    reg_data |= HPCF_MEDIUM;
    break;
  case ACCEL_MODE::HIGH:
    reg_data |= HPCF_HIGH;
    break;
  }
}

void LSM9DS0::SetReg4(ACCEL_MODE mode) const noexcept
{
  uint8_t reg_data = 0;
  reg_data |= BLE;
  switch (mode) {
  case ACCEL_MODE::LOW:reg_data |= DPS_245;
    break;
  case ACCEL_MODE::MEDDIUM:reg_data |= DPS_500;
    break;
  case ACCEL_MODE::HIGH:reg_data |= DPS_2000;
    break;
  }
}
}