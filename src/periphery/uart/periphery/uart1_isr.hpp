//
// Created by claiff on 6/13/21.
//

#pragma once

#include "periphery/gpio/gpio_init.hpp"
#include "periphery/types/ircc.hpp"
#include "periphery/types/periphery_init.h"

namespace kvadro::periphery::uart
{

  class UART1_ISR : public types::PeripheryInit
  {
  public:
	explicit UART1_ISR( types::IRCC_Ptr const& rcc );
	~UART1_ISR() override = default;

	void InitPeriphery() const noexcept override;

  private:
	types::IRCC_Ptr mRcc;
	gpio::GpioInit mGpioInit;
  };

}