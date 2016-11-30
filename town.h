//Programmer: ANDREW BRAY          ID: 12518487
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: town.h
//Description: Header file for the town class

#include <iostream>
using namespace std;

const short MAX_SIZE = 25;
const char WALL = 'W';
const char EXIT = 'E';

class town
{
  private:
    short size;
    char townMap[MAX_SIZE][MAX_SIZE];
    void build();
    void clear();
  public:
    town(const short townSize = MAX_SIZE):
     size(townSize) { clear(); build();}
    //Desc: This function returns the size of the town
    //Pre: none
    //Post: The size has been returned
    short getSize()const;

    //Desc: This allows the town to be displayed as a grid
    //Pre: None
    //Post: Returns the ostream and displays the town
    friend ostream& operator<<(ostream & out, const town & T);

      //Note: isWall and isExit are unused here, but will be needed for
      //      hw10 so I made them anyway
    //Desc: Checks to see if the passed character is a wall
    //Pre: None
    //Post: Returns whether the character is a wall
    bool isWall(const short row, const short col)const;

    //Desc: Checks to see if the passed character is an exit
    //Pre: None
    //Post: Returns whether or note the charaacter is an exit
    bool isExit(const short row, const short col)const;

    //Desc: The function returns the character value at the passed position
    //Pre: None
    //Post: THe character value at townMap[row][col] is returned
    char getSquare(const short row, const short col)const;

    //Desc: This sets the character at townMap[row][col] to val
    //Pre: None
    //Post: The tile has been changed
    void setSquare(const short row, const short col, const char val);
};
