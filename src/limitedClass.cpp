//***************************************************************************
// File name:  limitedClass.cpp
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#include "limitedClass.h"

//***************************************************************************
// Constructor: limitedClass
//
// Description: Initialized the object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
limitedClass::limitedClass()
{
  mpInt = nullptr;
}

//***************************************************************************
// Constructor: limitedClass
//
// Description: Initialized the object
//
// Parameters:  x - the value to place in mpInt
//
// Returned:    None
//***************************************************************************
limitedClass::limitedClass(int x) : mData(x)
{
  mpInt = new int;
  *mpInt = x;
}

//***************************************************************************
// Destructor:  limitedClass
//
// Description: Destory the object, delete dynamic int
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
limitedClass::~limitedClass()
{
  delete mpInt;
}

//***************************************************************************
// Function:    operator=
//
// Description: Assignment operator
//
// Parameters:  rcData - the object copy
//
// Returned:    None
//***************************************************************************
limitedClass& limitedClass::operator=(const limitedClass &rcData)
{
  mData = rcData.mData;

  delete mpInt;
  mpInt = nullptr;
  if (nullptr != rcData.mpInt)
  {
    mpInt = new int;
    *mpInt = *rcData.mpInt; 
  }
  return *this;
}