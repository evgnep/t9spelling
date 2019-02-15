#include <iostream>

#include "task.h"

int main()
{
  try {
    run(std::cin, std::cout);
  }
  catch (const std::exception& e) {
    std::cout << "Error: " << e.what();
  }
}
