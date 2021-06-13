//
// Created by claiff on 6/12/21.
//

#pragma once

#include "interface/ircc.h"

namespace kvadro::periphery
{
class SimpleRCC : public interface::IRCC
  {
public:
  SimpleRCC() = default;
  ~SimpleRCC() override = default;
  void SetDefaultRCC() const noexcept override;

private:
  static bool InitHSE() noexcept;
  static bool InitPLL() noexcept;
  void InitSW() const noexcept;
  static bool CheckRegister(const volatile uint32_t* base_reg, uint32_t check_reg) noexcept;
  static bool UnCheckRegister(const volatile uint32_t* base_reg, unsigned long check_reg) noexcept;
};
}

