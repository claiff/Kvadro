//
// Created by claiff on 6/13/21.
//

#pragma once

#include "memory"
#include "../../main/stm32f407xx.h"

namespace periphery::types
{
  static const int FUNC_BITS_SYS = 0x00;
  static const int FUNC_BITS_I2C = 0x04;
  static const int FUNC_BITS_UART = 0x07;

  class PeripheryInit
  {
  public:
	virtual ~PeripheryInit() = default;
	virtual void InitPeriphery() const noexcept = 0;
  };
  using PeripheryInitPtr = std::shared_ptr<PeripheryInit>;
}