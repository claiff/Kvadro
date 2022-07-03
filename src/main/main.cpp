#include "periphery/rcc/simple_rcc.hpp"

#include "periphery/uart/uart_gprs.hpp"
#include "devices/gps/gps_nmea.hpp"
#include "devices/radio_control/radio_control.hpp"
#include "periphery/timer/input_compare.hpp"

int main()
{
  auto clock_control = new periphery::SimpleRCC{};
  clock_control->SetDefaultRCC();
//  auto gps = new device::gps::GPS_NMEA{};
//  auto uart = new periphery::uart::UART_GPRS{ USART1, clock_control, gps };
//  for( volatile int i = 0; i < 0x5FFFFF; ++i )
//  {
//  }
//  volatile auto latitude = gps->GetLatitude();
//  volatile auto longtitude = gps->GetLongitude();
//  volatile auto time = gps->GetTime();
//  volatile auto speed = gps->GetSpeed();

	device::RadioControl radio_control;
	periphery::timer::InputCompare timer_input_compare{TIM1,clock_control, radio_control};

  while( 1 )
  {
	//volatile auto time = gps.GetTime();
  }
}


