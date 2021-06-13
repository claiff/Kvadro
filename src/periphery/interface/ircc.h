//
// Created by claiff on 6/12/21.
//

#pragma once

#include "memory"
#include "../../main/stm32f407xx.h"

namespace kvadro::periphery::interface
{

class IRCC
{
public:
  virtual ~IRCC() = default;

  virtual void SetDefaultRCC() const noexcept = 0;
};
using IRCC_Ptr = std::shared_ptr<IRCC>;
}


