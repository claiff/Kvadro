//
// Created by claiff on 6/10/21.
//
/*
@startuml
abstract class IAccel
{
 *-- I2CPtr i2c
 *-- SdCard sd_card
 -abstract ReadSettings()
}
@enduml
*/
#pragma once

namespace kvadro::device::Accel
{
    class IAccel
    {

    };
}

#endif //KVADRO_ACCEL_H
