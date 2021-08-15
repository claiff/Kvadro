//
// Created by claiff on 6/13/21.
//

#pragma once

#include "../../gpio/gpio_init.hpp"
#include "../../types/ircc.hpp"
#include "../../types/periphery_init.h"

namespace kvadro::periphery::uart
{

class UART1_ISR : public interface::PeripheryInit
{
public:
  explicit UART1_ISR( interface::IRCC_Ptr const& rcc);
  ~UART1_ISR() override = default;

  void InitPeriphery() const noexcept override;

private:
  interface::IRCC_Ptr mRcc;
  gpio::GpioInit mGpioInit;
};

}