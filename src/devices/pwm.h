//
// Created by claiff on 6/10/21.
//
/*
@startuml
class PWM
{
    +PWM()
    +SetMotorSpeed(m1 : uint8, m2 : uint8, m3 : uint8, m4 : uint8)
    +SetMotorSpeed(motor : struct Motor, speed : uint8)
    -struct Motor mM1
    -struct Motor mM2
    -struct Motor mM3
    -struct Motor mM4
}
@enduml
*/
#pragma once

namespace kvadro::device
{
    class PWM
    {

    };
}