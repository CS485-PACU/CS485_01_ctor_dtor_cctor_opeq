//***************************************************************************
// File name:  exampleClassCopyAndSwap.cpp
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#include "exampleClassCopyAndSwap.h"

//***************************************************************************
// Constructor: exampleClassCopyAndSwap
//
// Description: Initialized the object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
exampleClassCopyAndSwap::exampleClassCopyAndSwap ()
{

}

//***************************************************************************
// Constructor: exampleClassCopyAndSwap
//
// Description: Initialized the object
//
// Parameters:  x - the value to place in mpInt
//
// Returned:    None
//***************************************************************************
exampleClassCopyAndSwap::exampleClassCopyAndSwap (int x) : mData(x)
{
  mpInt = new int;
  *mpInt = x;
}

//***************************************************************************
// Destructor:  exampleClassCopyAndSwap
//
// Description: Destory the object, delete dynamic int
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
exampleClassCopyAndSwap::~exampleClassCopyAndSwap ()
{
  delete mpInt;
}

//***************************************************************************
// Constructor: exampleClassCopyAndSwap
//
// Description: Copy Constructor
//
// Parameters:  rcData - the object copy
//
// Returned:    None
//***************************************************************************
exampleClassCopyAndSwap::exampleClassCopyAndSwap (const exampleClassCopyAndSwap &rcData)
{
  mData = rcData.mData;

  if(nullptr != rcData.mpInt)
  {
    mpInt = new int;
    *mpInt = *rcData.mpInt;
  }
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
exampleClassCopyAndSwap& exampleClassCopyAndSwap::operator= (exampleClassCopyAndSwap rcData)
{
  std::swap(mData, rcData.mData);
  std::swap(mpInt, rcData.mpInt);

  return *this;
}

//***************************************************************************
// Function:    operator<<
//
// Description: Output object to stream
//
// Parameters:  rcOut - the stream to write to
//              rcObj - the object to output
//
// Returned:    the stream
//***************************************************************************
std::ostream& operator<<(std::ostream& rcOut, const exampleClassCopyAndSwap& rcObj)
{
  rcOut << rcObj.mData;
  if (nullptr != rcObj.mpInt)
  {
    rcOut << *rcObj.mpInt;
  }
  return rcOut;
}
