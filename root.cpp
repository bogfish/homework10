//Programmer: ANDREW BRAY, JOSHUA WARNER          ID: 12518487, 12522483
//Class: CS1570                    Section: A, B
//Date: 11/18/16                   File: root.cpp
//Description: CPP file for the root class

#include "root.h"

Root::Root()
{
  bool isPositive = myRand(1, 0);
  float randNum;

  if (isPositive)
  {
    effect =  myRand(POS_MAX, POS_MIN);
    desc = TRUFFLE;
  }
  else
  {
    effect = myRand(NEG_MAX, NEG_MIN);
    desc = SQUARE;
  }
}

short myRand(const short max, const short min)
{
  short retVal;
  retVal = rand() % (max - min +1) + min;
  return retVal;
}
