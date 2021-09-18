//
// Created by claiff on 9/18/21.
//

#pragma once

#include <cstdint>

namespace kvadro::device::gps::headers::types
{
  class IHeader
  {
  public:
	virtual ~IHeader() = default;

	virtual void AddData( uint8_t data ) = 0;
  };
}