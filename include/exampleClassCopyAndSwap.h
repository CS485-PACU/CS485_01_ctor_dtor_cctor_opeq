//***************************************************************************
// File name:  exampleClassCopyAndSwap.h
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#pragma once

#include <iostream>

class exampleClassCopyAndSwap
{
public:

  exampleClassCopyAndSwap (); 

  exampleClassCopyAndSwap (int x);

  ~exampleClassCopyAndSwap ();

  exampleClassCopyAndSwap (const exampleClassCopyAndSwap &rcData);

  // exampleClass (exampleClass &rcData); // gives multiple copy constructors defined error

  exampleClassCopyAndSwap& operator= (exampleClassCopyAndSwap rcData); // NOTE NO REFERENCE OR CONST

private:
  int mData = 0;
  int *mpInt;
};
/*
  // op=    #include <utility>
	using std::swap;
	swap(mpInt, cData.mpInt);
	return *this;
  */