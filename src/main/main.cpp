#include "main.hpp"
#include "../periphery/i2c/i2c_max_speed.hpp"
#include "../periphery/rcc/simple_rcc.hpp"
#include "memory"
#include "../periphery/uart/uart_gprs.hpp"
#include "../devices/accel/lsm9ds0.hpp"
#include "devices/gps/gps_nmea.hpp"
int main()
{
  auto clock_control = std::make_shared<kvadro::periphery::SimpleRCC>();
  clock_control->SetDefaultRCC();
  auto gps = std::make_shared<kvadro::device::gps::GPS_NMEA>();
  auto uart = std::make_shared<kvadro::periphery::uart::UART_GPRS>( USART1, clock_control, gps );
  for( volatile int i = 0; i < 0x5FFFFF; ++i )
  {
  }
  volatile auto latitude = gps->GetLatitude();
  volatile auto longtitude = gps->GetLongitude();
  volatile auto time = gps->GetTime();
  volatile auto speed = gps->GetSpeed();
  while( 1 )
  {
	//volatile auto time = gps.GetTime();
  }
}


