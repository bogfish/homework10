//Programmer: ANDREW BRAY, JOSHUA WARNER          ID: 12518487, 12522483
//Class: CS1570                    Section: A, B
//Date: 11/18/16                   File: root.cpp
//Description: CPP file for the root class

#include "root.h"

root::root()
{
  // randomly generate true or false for bool
  bool isPositive = myRand(1, 0);

  // Check if positive
  if (isPositive)
  {
    // Set effect and desc
    effect = myFRand(POS_MAX, POS_MIN);
    desc = TRUFFLE;
  }
  else
  {
    // Set effect and desc
    effect = myFRand(NEG_MAX, NEG_MIN);
    desc = SQUARE;
  }

}

// Getter for effect
float root:: getEffect()const
{
  return effect;
}
