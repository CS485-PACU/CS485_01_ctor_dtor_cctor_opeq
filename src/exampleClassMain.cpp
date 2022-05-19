//***************************************************************************
// File name:  exampleClassMain.cpp
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************

#include "exampleClass.h"
#include <iostream>



//***************************************************************************
// Function:    foo
//
// Description: Demonstrate pass by value
//
// Parameters:  b4 - the object passed in by value
//
// Returned:    None
//***************************************************************************
void foo (exampleClass b4)
{
}

//***************************************************************************
// Function:    bar
//
// Description: Demonstrate pass by value and return by value
//
// Parameters:  b5 - the object passed in by value
//
// Returned:    exampleClass - a copy of the parameter
//***************************************************************************
exampleClass bar (exampleClass b5)
{
  return b5;
}

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
int main ()
{
  std::cout << "b1\n";
  exampleClass b1;
  std::cout << "end b1\n\n";

  std::cout << "b2\n";
  exampleClass b2 (b1);
  std::cout << "end b2\n\n";

  std::cout << "b3\n";
  exampleClass b3 = b1;
  std::cout << "end b3\n\n";

  std::cout << "b6\n";
  exampleClass b6;
  std::cout << "end b6\n\n";

  std::cout << "foo\n";
  foo (b1);
  std::cout << "end foo\n\n";

  std::cout << "bar\n";
  b6 = bar (b1);
  std::cout << "end bar\n\n";

  std::cout << "b7\n";
  exampleClass b7 = 1;
  std::cout << "end b7\n\n";

  std::cout << "b8\n";
  foo (1);
  std::cout << "end b8\n\n";

  return EXIT_SUCCESS;
}