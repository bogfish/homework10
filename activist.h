//Programmer: ANDREW BRAY, JOSHUA WARNER          ID: 12518487, 12522483
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: activist.h
//Description: Header file for the activist class

#ifndef ACTIVIST_H
#define ACTIVIST_H

#include "root.h"

const char DEF_ACTIVIST = 'A';//Default character for the activist
const float MAX_TOX = 3;//Maximum and minimum toxicity
const float MIN_TOX = 0;
const short MAX_DIG = 100;//Maximum and minimum toxicity
const short MIN_DIG = 0;
const float START_TOX = .05;  // Starting toxicity and dignity
const short START_DIG = 100;
const string STATES[] = {"normal", "cool", "gone"};
const float FIRST_TOX_UP = .08;//These two will change the state according to
const float SECOND_TOX_UP = .25;//the STATES array

class activist
{
  private:
    float toxicity; // Toxicity
    short dignity;  // Dignity
    string name;  // Name of activist
    short row_loc;//Row and column location
    short col_loc;
    char arr_Char;  // Char representation
    string state; // State of activist
    char last_Char;//The character that was in the array before the activist
    short wall_Loss;//Dignity lost for running into a wall
    short cop_Loss;//Dignity lost for running into a cop
    bool lose;//Starts false, made true by touching an exit, getting too much
              //toxicity, or by having too little dignity
    bool win;//Starts false, made true by catching the polluter
    bool exited;//Starts false, made true by moving to an exit
  public:
    activist(const string n, const char space = DEF_ACTIVIST,
      const short wall = 0, const short cop = 0):
      toxicity(.05), dignity(100), name(n), row_loc(-1), col_loc(-1),
      arr_Char(space), state(STATES[0]), last_Char(SPACE), wall_Loss(wall),
      cop_Loss(cop), lose(false), win(false), exited(false) {}

    // Desc: Get bool value for win
    // Pre: None
    // Post:  Return bool value
    bool getWin()const;

    // Desc: Get bool value for lose
    // Pre: None
    // Post:  Return bool value
    bool getLose()const;

    // Desc: Get state of activist
    // Pre: None
    // Post:  Return state string
    string getState()const;

    //Desc: This places the activist in the center of town
    //Pre: None
    //Post: The activist has been placed in the center of town
    void placeMeInMiddle(town & t);

    //Desc: This moves the activist into an adjacent empty tile
    //Pre: None
    //Post: The activist has been moved
    void randMove(town & t);

    //Desc: This moves the activist towards the polluter
    //Pre: Toxicity must be lower than the "cool threshold"
    //Post: The activist has been moved towards the polluter
    void searchMove(town & t, const polluter & p);

    // Desc: Get the toxicity of activist
    // Pre: None
    // Post:  Return float value for toxicity
    float getTox()const;

    // Desc:  Get Dignity of activist
    // Pre: None
    // Post:  Return dignity
    short getDignity()const;

    //Desc: This overloads << to display characteristics of the activist
    //Pre: None
    //Post: Returns out and displays characterisitcs of the activist
    friend ostream& operator<<(ostream & out, const activist & A);

    // Desc: Overloaded += for adding root effect
    // Pre: Root must be declared (obviously)
    // Post: Return activist
    activist operator+=(const root& R);

};

#endif
