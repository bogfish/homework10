//Programmer: ANDREW BRAY, JOSHUA WARNER          ID: 12518487, 12522483
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: polluter.h
//Description: Header file for the polluter class

#ifndef POLLUTER_H
#define POLLUTER_H

#include "town.h"


class polluter
{
  private:
    string name;
    short row_loc;  // row location of polluter
    short col_loc;  // col location of polluter
    char arr_Char;  // Character to represent polluter
    bool is_Caught; // bool for being caught
    char last_Char; // Last char for movement
  public:
    polluter(const string n, const char c = DEF_POLLUTER):
      name(n), row_loc(-1), col_loc(-1), arr_Char(c),
      is_Caught(false), last_Char(SPACE) {}

    // Desc: Get character
    // Pre: None
    // Post: Return character of polluter
    char getChar()const;


    //Desc:Moves the polluter to an empty adjacent tile in a random direction
    //Pre: None
    //Post: The polluter has been moved one tile
    void random_move(town & T);

    //Desc: The polluter is placed in a random tile that is empty
    //Pre: None
    //Post: The polluter has been placed
    void place_me(town & T);

    //Desc: This gets the row position of the polluter
    //Pre: None
    //Post: Returns the row position of the polluter
    short getRow()const;

    //Desc: This gets the column of position of the polluter
    //Pre: None
    //Post: Returns the row position of the polluter
    short getCol()const;
};

#endif
