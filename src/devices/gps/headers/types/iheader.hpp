//
// Created by claiff on 9/18/21.
//

#pragma once

#include <cstdint>

namespace device::gps::headers::types
{
	class IGpsHeader
	{
	public:
		virtual ~IGpsHeader() = default;

		virtual void AddData( uint8_t data ) = 0;
	};

	using IGpsHeaderPtr = IGpsHeader*;
}