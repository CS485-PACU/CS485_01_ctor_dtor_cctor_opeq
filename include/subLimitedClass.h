//***************************************************************************
// File name:  subLimitedClass.h
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#pragma once

#include <iostream>

class subLimitedClass
{
public:

  subLimitedClass (); 

  explicit subLimitedClass (int x);

  virtual ~subLimitedClass ();

  subLimitedClass (const subLimitedClass &rcData) = delete;
  
  subLimitedClass& operator= (const subLimitedClass &rcData);

private:
  int mData = 0;
  int *mpSubInt;
};
