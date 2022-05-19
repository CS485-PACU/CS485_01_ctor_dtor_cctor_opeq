#include "subExampleClass.h"

subExampleClass::subExampleClass() : exampleClass()
{
  mSID = subExampleClass::getID();
  std::cout << "subExampleClass ctor ID: " << mSID << std::endl;
}

subExampleClass::subExampleClass(int x) : exampleClass(x)
{
  mSID = subExampleClass::getID();
  mpSubClassPtr = new int;
  subExampleClass::countNew();
  *mpSubClassPtr = x;
  std::cout << "subExampleClass ctor(int) ID: " << mSID << std::endl;
}

subExampleClass::~subExampleClass()
{
  std::cout << "subExampleClass dtor ID: " << mSID << std::endl;

  delete mpSubClassPtr;
}

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

subExampleClass& subExampleClass::operator=(const subExampleClass &rcData)
{
  std::cout << "subExampleClass op=(const subExampleClass&) ID: " << mSID << std::endl;

  exampleClass::operator=(rcData);

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
  return *this;
}

int subExampleClass::getID()
{
  static int id = 0;

  return id ++;
}

int subExampleClass::newCount = 0;

void subExampleClass::countNew()
{
  subExampleClass::newCount++;
}

int subExampleClass::getNewCount()
{
    return subExampleClass::newCount;
}


#ifndef WITHOUT_MOVE
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

subExampleClass& subExampleClass::operator= (subExampleClass &&rcData)
{
  // without std::move() the op=(exampleClass &) gets called!
  exampleClass::operator=(std::move(rcData));

  mData = rcData.mData;

  // steal the pointer
  mpSubClassPtr = rcData.mpSubClassPtr;
  // vital to set the stolen pointer to nullptr
  rcData.mpSubClassPtr = nullptr;

  std::cout << "subExampleClass op=(const subExampleClass&&) ID: " << mSID << std::endl;

  return *this;
}
#endif