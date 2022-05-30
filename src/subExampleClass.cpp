//***************************************************************************
// File name:  subExampleClass.cpp
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#include "subExampleClass.h"

//***************************************************************************
// Constructor: subExampleClass
//
// Description: Initialized the object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
subExampleClass::subExampleClass() : exampleClass()
{
  mSID = subExampleClass::getID();
  std::cout << "subExampleClass ctor ID: " << mSID << std::endl;
}

//***************************************************************************
// Constructor: subExampleClass
//
// Description: Initialized the object
//
// Parameters:  x - the value to place in mpInt
//
// Returned:    None
//***************************************************************************
subExampleClass::subExampleClass(int x) : exampleClass(x)
{
  mSID = subExampleClass::getID();
  mpSubClassPtr = new int;
  subExampleClass::countNew();
  *mpSubClassPtr = x;
  std::cout << "subExampleClass ctor(int) ID: " << mSID << std::endl;
}

//***************************************************************************
// Destructor:  subExampleClass
//
// Description: Destory the object, delete sub class pointer
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
subExampleClass::~subExampleClass()
{
  std::cout << "subExampleClass dtor ID: " << mSID << std::endl;

  delete mpSubClassPtr;
}

//***************************************************************************
// Constructor: subExampleClass
//
// Description: Copy Constructor
//
// Parameters:  rcData - the object copy
//
// Returned:    None
//***************************************************************************
subExampleClass::subExampleClass(const subExampleClass &rcData) : exampleClass(rcData)
{

  // cctor COULD call op=
  // REQUIRES operator= to take a reference.
  // what happens if operator= is pass by value?
  // this is not done here for clarity of
  // which function gets called when
  mSID = subExampleClass::getID();
  if ( this != &rcData ) 
  {
    mData = rcData.mData;
    if ( nullptr != rcData.mpSubClassPtr )
    {
      mpSubClassPtr = new int;
      subExampleClass::countNew();
      *mpSubClassPtr = *rcData.mpSubClassPtr;
    }
  }
  std::cout << "subExampleClass ctor(const subExampleClass&) ID: " << mSID << std::endl;
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
subExampleClass& subExampleClass::operator=(const subExampleClass &rcData)
{
  std::cout << "subExampleClass op=(const subExampleClass&) ID: " << mSID << std::endl;

  exampleClass::operator=(rcData);

  if ( this != &rcData ) 
  {
    mData = rcData.mData;
    delete mpSubClassPtr;
    mpSubClassPtr = nullptr;

    if ( nullptr != rcData.mpSubClassPtr )
    {
      mpSubClassPtr = new int;
      subExampleClass::countNew();
      *mpSubClassPtr = *rcData.mpSubClassPtr;
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
int subExampleClass::getID()
{
  static int id = 0;

  return id ++;
}

int subExampleClass::newCount = 0;

//***************************************************************************
// Function:    countNew
//
// Description: How how many times new is called, update static variable
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void subExampleClass::countNew()
{
  subExampleClass::newCount++;
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
int subExampleClass::getNewCount()
{
    return subExampleClass::newCount;
}


#ifndef WITHOUT_MOVE
//***************************************************************************
// Constructor: subExampleClass
//
// Description: Move Copy Constructor
//
// Parameters:  rcData - the object copy
//
// Returned:    None
//***************************************************************************
subExampleClass::subExampleClass (subExampleClass &&rcData) : 
  exampleClass(std::move(rcData)) // without std::move() the cctor(exampleClass &) gets called!
{
  mSID = subExampleClass::getID();

  // could call op=(&&)
  // but for clarity we do not.
  mData = rcData.mData;

  // steal the pointer
  mpSubClassPtr = rcData.mpSubClassPtr;
  // vital to set the stolen pointer to nullptr
  rcData.mpSubClassPtr = nullptr;
  std::cout << "subExampleClass ctor(const subExampleClass&&) ID: " << mSID << std::endl;

}

#include <utility>

//***************************************************************************
// Function:    Move operator=
//
// Description: Assignment operator
//
// Parameters:  rcData - the object copy
//
// Returned:    None
//***************************************************************************
subExampleClass& subExampleClass::operator= (subExampleClass &&rcData)
{
  // without std::move() the op=(exampleClass &) gets called!
  exampleClass::operator=(std::move(rcData));

  mData = rcData.mData;

  // steal the pointer
  delete mpSubClassPtr;
	mpSubClassPtr = rcData.mpSubClassPtr;

  // vital to set this parameter ptr to nullptr
  rcData.mpSubClassPtr = nullptr;

  std::cout << "subExampleClass op=(const subExampleClass&&) ID: " << mSID << std::endl;

  return *this;
}
#endif