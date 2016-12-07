//Programmer: ANDREW BRAY, JOSHUA WARNER        ID: 12518487, 12522483
//Class: CS1570                    Section: A, B
//Date: 11/18/16                   File: hw10.h
//Description: Header file for the homework 10 file, yo

#ifndef HW10_H
#define HW10_H

#include "activist.h"
#include <unistd.h>//Used to print the town in a readable way

using namespace std;

const short NUM_DAYS = 1;
const short NUM_SIM = 10;
const string CONFIG_FILE = "config.dat";
const long SLEEP = 450000;//Used to make the compiler wait .45 seconds before
                          //printing

//Desc: This function will simulate a single day in the town, with print
//      determining whether the town prints during this process
//Pre: None
//Post: A day will be run in the town. It will be printed if print is true
void simulate(const bool print, short & numWin, short & numExit, 
              short & numDigLose, short & numRootLose, float & sumTox);

#endif
