//***************************************************************************
// File name:  subExampleClass.h
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#pragma once

#include <iostream>

class subExampleClass
{
public:

  subExampleClass (); 

  subExampleClass (int x);

  ~subExampleClass ();

  subExampleClass (const subExampleClass &rcData);


  subExampleClass& operator= (const subExampleClass &rcData);

private:
  int mData = 0;

  int *mpSubClassPtr;
};
