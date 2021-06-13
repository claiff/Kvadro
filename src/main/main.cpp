
#include "main.hpp"
#include "../periphery/simple_rcc.h"
#include "memory"

int main()
{
  auto clock_control = std::make_shared<kvadro::periphery::SimpleRCC>();
  clock_control->SetDefaultRCC();
  while (1)
  {

  }
}
