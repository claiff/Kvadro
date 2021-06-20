//
// Created by claiff on 6/16/21.
//

#pragma once

#include <utility>

#include "../interfaces/iaccel.h"


static const uint8_t MAGN_ADDRESS = 0x3B;

static const uint8_t ACCEL_ADDRESS = 0xD6;
static const uint8_t WHO_AM_I_G = 0x0F;
  static const uint8_t WHO_AM_I_G_RET = 0xD6;
static const uint8_t CTRL_REG1_G = 0x20;
  static const uint8_t CUTOFF_12_5_ODR_95 = 0x00;
  static const uint8_t CUTOFF_25_ODR_190 = 0x05;
  static const uint8_t CUTOFF_50_ODR_190 = 0x06;
  static const uint8_t CUTOFF_70_ODR_190 = 0x07;
  static const uint8_t CUTOFF_20_ODR_380 = 0x08;
  static const uint8_t CUTOFF_25_ODR_380 = 0x09;
  static const uint8_t CUTOFF_50_ODR_380 = 0x0A;
  static const uint8_t CUTOFF_100_ODR_380 = 0x0B;
  static const uint8_t CUTOFF_30_ODR_760 = 0x0C;
  static const uint8_t CUTOFF_35_ODR_760 = 0x0D;
  static const uint8_t CUTOFF_50_ODR_760 = 0x0E;
  static const uint8_t CUTOFF_100_ODR_760 = 0x0F;
  static const uint8_t POWER_DOWN_MODE = 0x00;
  static const uint8_t NORMAL_MODE = 0x08;
  static const uint8_t ZEN = 0x04;
  static const uint8_t YEN = 0x02;
  static const uint8_t XEN = 0x01;
static const uint8_t CTRL_REG2_G = 0x21;
  static const uint8_t HPM_NORMAL_MODE_RES = 0x00;
  static const uint8_t HPM_REF_SIG = 0x10;
  static const uint8_t HPM_NORMAL_MODE = 0x20;
  static const uint8_t HPM_AUTO_RESET = 0x30;
  static const uint8_t HPCF_LOW = 0x00;
  static const uint8_t HPCF_MEDIUM = 0x04;
  static const uint8_t HPCF_HIGH = 0x09;
static const uint8_t CTRL_REG3_G = 0x22;
  static const uint8_t I2_EMPTY = 0x01;
  static const uint8_t I2_ORUN = 0x02;
  static const uint8_t I2_WTM = 0x04;
  static const uint8_t I2_DRDY = 0x08;
  static const uint8_t PP_OD = 0x10;
  static const uint8_t H_LACTIVE = 0x20;
  static const uint8_t I1_BOOT = 0x40;
  static const uint8_t I1_INT1 = 0x80;
static const uint8_t CTRL_REG4_G = 0x23;
  static const uint8_t BDU = 0x80;
  static const uint8_t BLE = 0x40;
  static const uint8_t DPS_245 = 0x00;
  static const uint8_t DPS_500 = 0x10;
  static const uint8_t DPS_2000 = 0x30;
static const uint8_t CTRL_REG5_G = 0x24;
  static const uint8_t BOOT = 0x80;
  static const uint8_t FIFO_EN = 0x40;
  static const uint8_t HP_EN = 0x20;
  static const uint8_t LPF1_I = 0x00;
  static const uint8_t HPF_I = 0x04;
  static const uint8_t LPF2_I = 0x0C;
  static const uint8_t LPF1_O = 0x00;
  static const uint8_t HPF_O = 0x01;
  static const uint8_t LPF2_O = 0x03;
static const uint8_t STATUS_REG_G = 0x27;
  static const uint8_t ZYXOR = 0x80;
  static const uint8_t ZOR = 0x40;
  static const uint8_t YOR = 0x20;
  static const uint8_t XOR = 0x10;
  static const uint8_t ZYXDAZDA = 0x08;
  static const uint8_t ZDA = 0x04;
  static const uint8_t YDA = 0x02;
  static const uint8_t XDA = 0x01;
static const uint8_t OUT_X_L_G = 0x28;
static const uint8_t OUT_X_H_G = 0x29;
static const uint8_t OUT_Y_L_G = 0x2A;
static const uint8_t OUT_Y_H_G = 0x2B;
static const uint8_t OUT_Z_L_G = 0x2C;
static const uint8_t OUT_Z_H_G = 0x2D;
static const uint8_t FIFO_CTRL_REG_G = 0x2E;
  static const uint8_t BYPASS_MODE = 0x00;
  static const uint8_t FIFO_MODE = 0x20;
  static const uint8_t STREAM_MODE = 0x40;
  static const uint8_t STREAM_TO_FIFO_MODE = 0x60;
  static const uint8_t BYPASS_TO_STREAM_MODE = 0x80;
static const uint8_t FIFO_SRC_REG_G = 0x2F;
  static const uint8_t WATERMARK_STATUS = 0x80;
  static const uint8_t OVR = 0x40;
  static const uint8_t EMPTY = 0x20;
static const uint8_t INT1_CFG_G = 0x30;
//TODO interrupts
namespace kvadro::device::accel
{
  class LSM9DS0 : public IAccel
  {
  public:
    explicit LSM9DS0(periphery::interface::I2CPtr I2C) : IAccel(std::move(I2C)) {};
    [[nodiscard]] bool IsAccelOnline() const noexcept override;
    [[nodiscard]] bool SetAccelMode(ACCEL_MODE mode) const noexcept override;
  private:
    void SetReg1(ACCEL_MODE mode) const noexcept;
    void SetReg2(ACCEL_MODE mode) const noexcept;
    void SetReg3() const noexcept;
    void SetReg4(ACCEL_MODE mode) const noexcept;
  };
}
