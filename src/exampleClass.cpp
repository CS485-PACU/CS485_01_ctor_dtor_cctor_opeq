//***************************************************************************
// File name:  exampleClass.cpp
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#include "exampleClass.h"

//***************************************************************************
// Constructor: exampleClass
//
// Description: Initialized the object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
exampleClass::exampleClass()
{
  mID = exampleClass::getID();
  std::cout << "exampleClass ctor ID: " << mID << std::endl;
}

//***************************************************************************
// Constructor: exampleClass
//
// Description: Initialized the object
//
// Parameters:  x - the value to place in mpInt
//
// Returned:    None
//***************************************************************************
exampleClass::exampleClass(int x) : mData(x)
{
  mID = exampleClass::getID();
  mpInt = new int;
  exampleClass::countNew();
  *mpInt = x;
  std::cout << "exampleClass ctor(int) ID: " << mID << std::endl;
}

//***************************************************************************
// Destructor:  exampleClass
//
// Description: Destory the object, delete dynamic int
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
exampleClass::~exampleClass()
{
  std::cout << "exampleClass dtor ID: " << mID << std::endl;

  delete mpInt;
}

//***************************************************************************
// Constructor: exampleClassCopy
//
// Description: Copy Constructor
//
// Parameters:  rcData - the object copy
//
// Returned:    None
//***************************************************************************
exampleClass::exampleClass(const exampleClass &rcData)
{

  // cctor COULD call op=
  // REQUIRES operator= to take a reference.
  // what happens if operator= is pass by value?
  // this is not done here for clarity of
  // which function gets called when
  mID = exampleClass::getID();
  if ( this != &rcData ) 
  {
    mData = rcData.mData;

    if ( nullptr != rcData.mpInt )
    {
      mpInt = new int;
      exampleClass::countNew();
      *mpInt = *rcData.mpInt;
    }
  }
  std::cout << "exampleClass ctor(const exampleClass&) ID: " << mID << std::endl;
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
exampleClass& exampleClass::operator=(const exampleClass &rcData)
{
  std::cout << "exampleClass op=(const exampleClass&) ID: " << mID << std::endl;

  if ( this != &rcData ) 
  {
    mData = rcData.mData;
    delete mpInt;
    mpInt = nullptr;

    if ( nullptr != rcData.mpInt )
    {
      mpInt = new int;
      exampleClass::countNew();
      *mpInt = *rcData.mpInt;
    }
  }
  return *this;
}

//***************************************************************************
// Function:    getID
//
// Description: Get a unique ID for an object
//
// Parameters:  None
//
// Returned:    the ID
//***************************************************************************
int exampleClass::getID()
{
  static int id = 0;

  return id ++;
}

int exampleClass::newCount = 0;

//***************************************************************************
// Function:    countNew
//
// Description: How how many times new is called, update static variable
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void exampleClass::countNew()
{
  exampleClass::newCount++;
}

//***************************************************************************
// Function:    getNewCount
//
// Description: Get static variable that counts the number of new calls
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
int exampleClass::getNewCount()
{
    return exampleClass::newCount;
}


#ifndef WITHOUT_MOVE
//***************************************************************************
// Constructor: exampleClassCopy
//
// Description: Move Copy Constructor
//
// Parameters:  rcData - the object copy
//
// Returned:    None
//***************************************************************************
exampleClass::exampleClass (exampleClass &&rcData)
{
  mID = exampleClass::getID();

  // could call op=(&&)
  // but for clarity we do not.
  mData = rcData.mData;

  // steal the pointer
  mpInt = rcData.mpInt;
  // vital to set the stolen pointer to nullptr
  rcData.mpInt = nullptr;
  std::cout << "exampleClass ctor(const exampleClass&&) ID: " << mID << std::endl;

}

//***************************************************************************
// Function:    Move operator=
//
// Description: Assignment operator
//
// Parameters:  rcData - the object copy
//
// Returned:    None
//***************************************************************************
exampleClass& exampleClass::operator= (exampleClass &&rcData)
{
  mData = rcData.mData;

  // steal the pointer
  delete mpInt;
  mpInt = rcData.mpInt;

  // vital to set this parameter pointer to nullptr!
  rcData.mpInt = nullptr;
  std::cout << "exampleClass op=(const exampleClass&&) ID: " << mID << std::endl;

  return *this;
}
#endif