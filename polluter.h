//Programmer: ANDREW BRAY          ID: 12518487
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: polluter.h
//Description: Header file for the polluter class

#include "activist.h"


class polluter
{
  private:
    string name;
    short row_loc;
    short col_loc;
    char arr_Char;
  public:
    polluter(const string n):
      name(n), row_loc(-1), col_loc(-1), arr_Char('P') {}

    //Desc:Moves the polluter to an empty adjacent tile in a random direction
    //Pre: None
    //Post: The polluter has been moved one tile
    void random_move(town & T);

    //Desc: The polluter is placed in a random tile that is empty
    //Pre: None
    //Post: THe polluter has been placed
    void place_me(town & T);
};
