//***************************************************************************
// File name:  limitedClassMain.cpp
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************

#include "limitedClass.h"
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
void foo (limitedClass b4)
{
  std::cout << "inside foo" << std::endl;
}

//***************************************************************************
// Function:    bar
//
// Description: Demonstrate pass by value and return by value
//
// Parameters:  b5 - the object passed in by value
//
// Returned:    limitedClass - a copy of the parameter
//***************************************************************************
/*limitedClass*/ void bar (limitedClass b5)
{
  std::cout << "inside bar" << std::endl;
   // return b5; // error, no cctor
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
  std::cout << "b0\n";
  limitedClass b0;
  std::cout << "end b0\n\n";

  std::cout << "b1\n";
  limitedClass b1(1);
  std::cout << "end b1\n\n";

  std::cout << "b2\n";
  // limitedClass b2 (b1); // error, no cctor
  std::cout << "end b2\n\n";

  std::cout << "b3\n";
  // limitedClass b3 = b1; // error, no cctor
  std::cout << "end b3\n\n";

  std::cout << "b6\n";
  limitedClass b6;
  std::cout << "end b6\n\n";

  std::cout << "foo\n";
  // foo (b1); // error, no cctor
  std::cout << "end foo\n\n";

  std::cout << "bar\n";
  // b6 = bar (b1); // error, no cctor
  std::cout << "end bar\n\n";

  std::cout << "b7\n";
  // limitedClass b7 = 1; // error, no converting ctor
  std::cout << "end b7\n\n";

  std::cout << "b8\n";
  // foo (1); // error, no converting ctor
  std::cout << "end b8\n\n";

  return EXIT_SUCCESS;
}