//
// Created by claiff on 6/11/21.
//

#include "radio_control.hpp"

namespace device
{
	RadioControl::RadioControl()
			: mIsInit{false}
			, mCounter{0}
	{

	}

	void RadioControl::AddData( uint32_t value )
	{
		if( !IsInitRadio( value ))
		{
			return;
		}

		mChannelsData[mCounter++] = value;
		if( mCounter == COUNT_CHANNELS )
		{
			mCounter = 0;
		}
	}

	bool RadioControl::IsInitRadio( uint32_t value )
	{
		static constexpr uint16_t PAUSE_PERIOD = 800;

		if( mIsInit )
		{
			return true;
		}

		if( value > PAUSE_PERIOD )
		{
			mIsInit = true;
		}
		return mIsInit;
	}
}