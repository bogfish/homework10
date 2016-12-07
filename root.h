//Programmer: ANDREW BRAY, JOSHUA WARNER        ID: 12518487, 12522483
//Class: CS1570                    Section: A, B
//Date: 11/18/16                   File: root.h
//Description: Header file for the root class

#ifndef ROOT_H
#define ROOT_H

#include "polluter.h"

using namespace std;

const float NEG_MIN = -0.001; // Negative effect minimum
const float NEG_MAX = -0.010; // Negative effect maximum
const float POS_MIN = 0.05; // Positive effect minimum
const float POS_MAX = 0.10; // Positive effect maximum
const string TRUFFLE = "Truffle"; // String for Truffle
const string SQUARE = "Square";   // String for Square

class root
{
  private:
    string desc;
    float effect;
  public:
    root();

    // Desc: Get effect of root
    // Pre: none
    // Post: Return float value for effect
    float getEffect()const;
};

#endif
