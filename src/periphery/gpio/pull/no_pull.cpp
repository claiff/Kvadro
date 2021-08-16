//
// Created by claiff on 6/13/21.
//

#include "no_pull.hpp"

namespace kvadro::periphery::gpio::pull
{

  void PullNo::SetPull( GPIO_TypeDef *gpio, uint8_t pin ) noexcept
  {
	static const int PULL_NO = 0x00;
	mPull = PULL_NO;
	GpioPull::SetPull( gpio, pin );
  }

}