//***************************************************************************
// File name:  exampleClassCopyAndSwapMain.cpp
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#include "exampleClassCopyAndSwap.h"
#include <iostream>

//***************************************************************************
// Function:    main
//
// Description: Demonstrate how constructors, destructors, and operator=
//              are invoked.
//
// Parameters:  None
//
// Returned:    int - EXIT_SUCCESS
//***************************************************************************
int main()
{
  exampleClassCopyAndSwap c1(9);

  exampleClassCopyAndSwap c2;

  c2 = c1;

  std::cout << "C1: " << c1 << std::endl;
  std::cout << "C2: " << c2 << std::endl;

  return EXIT_SUCCESS;
  
}