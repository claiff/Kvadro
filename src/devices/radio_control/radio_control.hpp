//
// Created by claiff on 6/11/21.
//

#pragma once

#include <cstdint>
#include <array>

namespace device
{
	static constexpr uint8_t COUNT_CHANNELS = 8;

	class RadioControl
	{
	public:
		RadioControl();
		~RadioControl() = default;

		void AddData( uint32_t value );
	private:
		bool IsInitRadio( uint32_t value );

		bool mIsInit;
		uint8_t mCounter;
		std::array < uint32_t, COUNT_CHANNELS > mChannelsData;
	};
}
