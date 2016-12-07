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
    short row_loc;
    short col_loc;
    char arr_Char;
    bool is_Caught;
    char last_Char;
    bool win;
  public:
    polluter(const string n):
      name(n), row_loc(-1), col_loc(-1), arr_Char(DEF_POLLUTER),
      is_Caught(false), last_Char(SPACE) {}

    char getChar()const;

    bool getWin()const;

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
