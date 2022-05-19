//***************************************************************************
// File name:  limitedClass.h
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#pragma once

#include <iostream>

class limitedClass
{
public:

  limitedClass (); 

  explicit limitedClass (int x);

  virtual ~limitedClass ();

  limitedClass (const limitedClass &rcData) = delete;
  
  limitedClass& operator= (const limitedClass &rcData);

private:
  int mData = 0;
  int *mpInt;
};
