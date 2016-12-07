//Programmer: ANDREW BRAY, JOSHUA WARNER          ID: 12518487, 12522483
//Class: CS1570                    Section: A, B
//Date: 11/18/16                   File: root.cpp
//Description: CPP file for the root class

#include "root.h"

root::root()
{
  bool isPositive = myRand(1, 0);

  if (isPositive)
  {
    effect = myFRand(POS_MAX, POS_MIN);
    desc = TRUFFLE;
  }
  else
  {
    effect = myFRand(NEG_MAX, NEG_MIN);
    desc = SQUARE;
  }

}

float root:: getEffect()const
{
  return effect;
}
