//
// Created by claiff on 6/13/21.
//

#include "push_pull.hpp"

namespace kvadro::periphery::gpio::output_type
{
  const int PUSH_PULL_TYPE = 0x00;
  PushPullType::PushPullType() :
	  periphery::interface::gpio::GpioOutputType( PUSH_PULL_TYPE )
  {

  }
  void PushPullType::SetOutputType( GPIO_TypeDef *gpio, uint16_t group_pins ) noexcept
  {
	GpioOutputType::SetOutputType( gpio, group_pins );
  }

}