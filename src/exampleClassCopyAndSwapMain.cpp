#include "exampleClassCopyAndSwap.h"
#include <iostream>

int main()
{
  exampleClassCopyAndSwap c1(9);

  exampleClassCopyAndSwap c2;

  c2 = c1;

  std::cout << "C1: " << c1 << std::endl;
  std::cout << "C2: " << c2 << std::endl;

  return EXIT_SUCCESS;
  
}