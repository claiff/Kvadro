//
// Created by claiff on 6/10/21.
//
/*
@startuml
class GPS
{
    +GPS(period : uint8)
    +GetDate() : DateTime
    +IsActive() : bool
    +GetLongitude() : struct coordinate
    +GetLatitude() : struct coordinate

    +SetTimerPeriod(timer_period : uint8);
    +GetTimerPeriod() : uint8;

    -mPeriod : uint8
    -mLongitude : struct coordinate
    -mLatitude : struct coordinate
    -mDate : DateTime
    - isActive : bool
}
@enduml
*/
#pragma once

namespace kvadro::device
{
    class GPS
    {

    };
}