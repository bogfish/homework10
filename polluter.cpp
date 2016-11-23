//Programmer: ANDREW BRAY          ID: 12518487
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: polluter.cpp
//Description: Function file for the polluter class

#include "polluter.h"

void polluter:: random_move(town & t)
{
  short ran;    //Will be use to generate number 1 - 8 to represent movement
                         //1 2 3
                         //4 A 5
                         //6 7 8
  short r = row_loc;
  short c = col_loc;
  bool done = false;//Used to determine if the polluter has been moved
  do//This loop moves the polluter into a random adjacent empty location
  {
    ran = myRand(8,1);
    if(ran == 1)
    {
      if(t.getSquare(r-1,c-1) == ' ')
      {
        t.setSquare(r, c, ' ');
        row_loc--;
        col_loc--;
        t.setSquare(row_loc, col_loc, arr_Char);
        done = true;
      }
    }
    else if(ran == 2)
    {
      if(t.getSquare(r-1,c) == ' ')
      {
        t.setSquare(r, c, ' ');
        row_loc--;
        t.setSquare(row_loc, c, arr_Char);
        done = true;
      }
    }
    else if(ran == 3)
    {
      if(t.getSquare(r-1,c+1) == ' ')
      {
        t.setSquare(r, c, ' ');
        row_loc--;
        col_loc++;
        t.setSquare(row_loc, col_loc, arr_Char);
        done = true;
      }
    }
    else if(ran == 4)
    {
      if(t.getSquare(r,c-1) == ' ')
      {
        t.setSquare(r, c, ' ');
        col_loc--;
        t.setSquare(row_loc, col_loc, arr_Char);
        done = true;
      }
    }
    else if(ran == 5)
    {
      if(t.getSquare(r,c+1) == ' ')
      {
        t.setSquare(r, c, ' ');
        col_loc++;
        t.setSquare(row_loc, col_loc, arr_Char);
        done = true;
      }
    }
    else if(ran == 6)
    {
      if(t.getSquare(r+1,c-1) == ' ')
      {
        t.setSquare(r, c, ' ');
        col_loc--;
        row_loc++;
        t.setSquare(row_loc, col_loc, arr_Char);
        done = true;
      }
    }
    else if(ran == 7)
    {
      if(t.getSquare(r+1,c) == ' ')
      {
        t.setSquare(r, c, ' ');
        row_loc++;
        t.setSquare(row_loc, col_loc, arr_Char);
        done = true;
      }
    }
    else if(ran == 8)
    {
      if(t.getSquare(r+1,c+1) == ' ')
      {
        t.setSquare(r, c, ' ');
        col_loc++;
        row_loc++;
        t.setSquare(row_loc, col_loc, arr_Char);
        done = true;
      }
    }
  }while(!done);
  return;
}

void polluter:: place_me(town & T)
{
  short randRow;
  short randCol;
  bool finished = false;// Used to determine if the polluter is placed
  short size = T.getSize();
  do//This loop places the polluter in an empty space
  {
    randRow = myRand(size, 0);
    randCol = myRand(size, 0);
    if(T.getSquare(randRow, randCol) == ' ')
    {
      T.setSquare(row_loc, col_loc, ' ');
      row_loc = randRow;
      col_loc = randCol;
      T.setSquare(row_loc, col_loc, arr_Char);
      finished = true;
    }
  }while(!finished);
  return;
}
