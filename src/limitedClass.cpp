#include "limitedClass.h"

limitedClass::limitedClass()
{
  mpInt = nullptr;
}

limitedClass::limitedClass(int x) : mData(x)
{
  mpInt = new int;
  *mpInt = x;
}

limitedClass::~limitedClass()
{
  delete mpInt;
}

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