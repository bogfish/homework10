//Programmer: ANDREW BRAY          ID: 12518487
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: activist.h
//Description: Header file for the activist class

#include "town.h"
#include <cstdlib>


const float MAX_TOX = 3;//Maximum and minimum toxicity
const float MIN_TOX = 0;
const short MAX_DIG = 100;//Maximum and minimum toxicity
const short MIN_DIG = 0;
const string STATES[] = {"normal", "gone", "cool"};

class activist
{
  private:
    float toxicity;
    short dignity;
    string name;
    short row_loc;//Row and column location
    short col_loc;
    char arr_Char;
    string state;
  public:
    activist(const string n, const char space = 'A'):
      toxicity(.05), dignity(100), name(n), row_loc(-1), col_loc(-1),
      arr_Char(space), state(STATES[0]) {}

    //Desc: This places the activist in the center of town
    //Pre: None
    //Post: The activist has been placed in the center of town
    void placeMeInMiddle(town & t);

    //Desc: This moves the activist into an adjacent empty tile
    //Pre: None
    //Post: The activist has been moved
    void randMove(town & t);

    //Desc: This overloads << to display characteristics of the activist
    //Pre: None
    //Post: Returns out and displays characterisitcs of the activist
    friend ostream& operator<<(ostream & out, const activist & A);
};

//Desc: Generates a random number between max and min
//Pre: none
//Post: Returns a random number between max and min
short myRand(const short max, const short min);
