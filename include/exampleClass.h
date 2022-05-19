//***************************************************************************
// File name:  exampleClass.h
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#pragma once

#include <iostream>

class exampleClass
{
public:

  exampleClass (); 

  exampleClass (int x);

  virtual ~exampleClass ();

  exampleClass (const exampleClass &rcData);

  // exampleClass (exampleClass &rcData); // gives multiple copy constructors defined error

  exampleClass& operator= (const exampleClass &rcData);

#ifndef WITHOUT_MOVE
  // MOVE
  exampleClass (exampleClass &&rcData);
  exampleClass& operator= (exampleClass &&rcData);
#endif

  static int getNewCount();

private:
  int mID;
  int mData = 0;
  int *mpInt = nullptr;
  static int getID();
  static void countNew();
  static int newCount;
};
