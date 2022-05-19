#include "exampleClass.h"

exampleClass::exampleClass()
{
  mID = exampleClass::getID();
  std::cout << "exampleClass ctor ID: " << mID << std::endl;
}

exampleClass::exampleClass(int x) : mData(x)
{
  mID = exampleClass::getID();
  mpInt = new int;
  *mpInt = x;
  std::cout << "exampleClass ctor(int) ID: " << mID << std::endl;
}

exampleClass::~exampleClass()
{
  std::cout << "exampleClass dtor ID: " << mID << std::endl;

  delete mpInt;
}

exampleClass::exampleClass(const exampleClass &rcData)
{

  // REQUIRES operator= to take a reference.
  // what happens if operator= is pass by value?
  mID = exampleClass::getID();
  *this = rcData;

  std::cout << "exampleClass ctor(const exampleClass&) ID: " << mID << std::endl;
}

exampleClass& exampleClass::operator=(const exampleClass &rcData)
{
  std::cout << "exampleClass op= ID: " << mID << std::endl;

  if ( this != &rcData ) 
  {
    mData = rcData.mData;

    if ( nullptr != rcData.mpInt )
    {
      mpInt = new int;
      *mpInt = *rcData.mpInt;
    }
  }
  return *this;
}

int exampleClass::getID()
{
  static int id = 0;

  return id ++;
}