#include "exampleClassCopyAndSwap.h"

  exampleClassCopyAndSwap::exampleClassCopyAndSwap ()
  {

  }

  exampleClassCopyAndSwap::exampleClassCopyAndSwap (int x) : mData(x)
  {
    mpInt = new int;
    *mpInt = x;
  }

  exampleClassCopyAndSwap::~exampleClassCopyAndSwap ()
  {
    delete mpInt;
  }

  exampleClassCopyAndSwap::exampleClassCopyAndSwap (const exampleClassCopyAndSwap &rcData)
  {
    mData = rcData.mData;

    if(nullptr != rcData.mpInt)
    {
      mpInt = new int;
      *mpInt = *rcData.mpInt;
    }
  }

  exampleClassCopyAndSwap& exampleClassCopyAndSwap::operator= (exampleClassCopyAndSwap rcData)
  {
    std::swap(mData, rcData.mData);
    std::swap(mpInt, rcData.mpInt);

    return *this;
  }

std::ostream& operator<<(std::ostream& rcOut, const exampleClassCopyAndSwap& rcObj)
{
  rcOut << rcObj.mData;
  if (nullptr != rcObj.mpInt)
  {
    rcOut << *rcObj.mpInt;
  }
  return rcOut;
}
