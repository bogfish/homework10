//Programmer: ANDREW BRAY          ID: 12518487
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: polluter.cpp
//Description: Function file for the polluter class

#include "polluter.h"

void polluter:: random_move(town & t)
{
  short ran;//Will be used to generate number 1 - 4 to represent movement
                         //  1
                         //4 A 2
                         //  3
  short r = row_loc;//Because I'm too lazy to type row_loc and col_loc
  short c = col_loc;
  bool done = false;//Checks to see if the activist was able to move
  char currentSquare; //To be used to set the square in the town map. NOT USED
  if(!is_Caught)
  {
    ran = myRand(4,1);
    if(ran == 1)
    {
      if(!t.isWall(r-1,c) && !t.isExit(r-1,c))
      {
        if(t.isCop(r-1,c))
          is_Caught = true;
        t.setSquare(r, c, last_Char);
        last_Char = getSquare(r-1,c);
        row_loc--;
        t.setSquare(row_loc, col_loc, arr_Char);
      }

    }
    else if(ran == 2)
    {
      if(!t.isWall(r,c+1) && !t.isExit(r,c+1))
      {
        if(t.isCop(r,c+1))
          is_Caught = true;
        t.setSquare(r, c, last_Char);
        last_Char = getSquare(r,c+1);
        col_loc--;
        t.setSquare(r, col_loc, arr_Char);
      }
    }
    else if(ran == 3)
    {
      if(!t.isWall(r+1,c) && !t.isExit(r+1,c))
      {
        if(t.isCop(r+1,c))
          is_Caught = true;
        t.setSquare(r, c, last_Char);
        last_Char = getSquare(r+1,c);
        row_loc++;
        t.setSquare(row_loc, col_loc, arr_Char);
      }
    }
    else if(ran == 4)
    {
      if(!t.isWall(r,c-1) && !t.isExit(r,c-1))
      {
        if(t.isCop(r,c-1))
          is_Caught = true;
        t.setSquare(r, c, last_Char);
        last_Char = getSquare(r,c-1);
        col_loc--;
        t.setSquare(row_loc, col_loc, arr_Char);
      }
    }
  }

  return;
}

void polluter:: place_me(town & t)
{
  bool placed = false;
  short randCol;
  short randRow;

  while(!placed)
  {
    randCol = myRand(t.getSize(), 0);
    randRow = myRand(t.getSize(), 0);
    if(t.getSquare(randRow, randCol) == SPACE)
    {
      t.setSquare(randRow, randCol, arr_Char);
      row_loc = randRow;
      col_loc = randCol;
    }
  }
  return;
}

short polluter:: getRow()
{
  return row_loc;
}

short polluter:: getCol()
{
  return col_loc;
}
