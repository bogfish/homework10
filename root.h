//Programmer: ANDREW BRAY, JOSHUA WARNER        ID: 12518487, 12522483
//Class: CS1570                    Section: A, B
//Date: 11/18/16                   File: root.h
//Description: Header file for the root class

#ifndef ROOT_H
#define ROOT_H

#include "activist.h"

using namespace std;

const float NEG_MIN = -0.001;
const float NEG_MAX = -0.010;
const float POS_MIN = 0.05;
const float POS_MAX = 0.10;
const string TRUFFLE = "Truffle";
const string SQUARE = "Square";

class Root
{
  private:
    string desc;
    float effect;
  public:
    Root();
};

#endif
