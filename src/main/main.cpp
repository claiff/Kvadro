
#include "main.hpp"
#include "../periphery/i2c/i2c_max_speed.hpp"
#include "../periphery/rcc/simple_rcc.hpp"
#include "memory"
#include "../periphery/uart/uart_gprs.hpp"
#include "../devices/accel/lsm9ds0.hpp"

int main()
{
  auto clock_control = std::make_shared<kvadro::periphery::SimpleRCC>();
  clock_control->SetDefaultRCC();
auto uart = std::make_shared<kvadro::periphery::uart::UART_GPRS>(USART1, clock_control);
  while (1)
  {

  }
}


