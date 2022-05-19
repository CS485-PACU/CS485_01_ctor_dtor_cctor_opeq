//***************************************************************************
// File name:  subExampleClass.h
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#pragma once

#include "exampleClass.h"

#include <iostream>

class subExampleClass : public exampleClass
{
public:

  subExampleClass (); 

  subExampleClass (int x);

  virtual ~subExampleClass ();

  subExampleClass (const subExampleClass &rcData);


  subExampleClass& operator= (const subExampleClass &rcData);

#ifndef WITHOUT_MOVE
  // MOVE
  subExampleClass (subExampleClass &&rcData);
  subExampleClass& operator= (subExampleClass &&rcData);
#endif

static int getNewCount();

private:
  int mSID;
  int mData = 0;
  int *mpSubClassPtr = nullptr;

  static int getID();
  static void countNew();
  static int newCount;


};
