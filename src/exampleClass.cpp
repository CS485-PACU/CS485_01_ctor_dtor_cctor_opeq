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
  exampleClass::countNew();
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

int exampleClass::getID()
{
  static int id = 0;

  return id ++;
}

int exampleClass::newCount = 0;

void exampleClass::countNew()
{
  exampleClass::newCount++;
}

int exampleClass::getNewCount()
{
    return exampleClass::newCount;
}


#ifndef WITHOUT_MOVE
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