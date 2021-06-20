
#include "main.hpp"
#include "../periphery/i2c/i2c_max_speed.hpp"
#include "../periphery/rcc/simple_rcc.hpp"
#include "memory"
#include "../devices/accel/lsm9ds0.hpp"

int main()
{
  auto clock_control = std::make_shared<kvadro::periphery::SimpleRCC>();
  clock_control->SetDefaultRCC();
  auto i2c = std::make_shared<kvadro::periphery::i2c::I2cMaxSpeed>(I2C1, clock_control);

  auto lsm = std::make_shared<kvadro::device::accel::LSM9DS0>(i2c);
  lsm->IsAccelOnline();
  //auto lsm = new kvadro::device::accel::LSM9DS0(i2c);
  while (1)
  {

  }
}
