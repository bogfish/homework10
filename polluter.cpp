//Programmer: ANDREW BRAY, JOSHUA WARNER          ID: 12518487, 12522483
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

    // check if caught
    if(!is_Caught)
    {
      // Generate move
      ran = myRand(4,1);
      // Check if move is up
      if(ran == 1)
      {
        if(!t.isWall(r-1,c) && !t.isExit(r-1, c))
        {
          if(t.isSpace(r-1, c) || t.isRoot(r-1, c) || t.isCop(r-1, c))
          {
            if(t.isCop(r-1,c))
              is_Caught = true;
            t.setSquare(r, c, last_Char);
            last_Char = t.getSquare(r-1,c);
            row_loc--;
            t.setSquare(row_loc, col_loc, arr_Char);
          }

        }
      }
      // Check if move is right
      else if(ran == 2)
      {
        if(!t.isWall(r,c+1) && !t.isExit(r,c+1))
        {
          if(t.isSpace(r, c+1) || t.isRoot(r, c+1) || t.isCop(r, c+1))
          {
            if(t.isCop(r,c)+1)
              is_Caught = true;
            t.setSquare(r, c, last_Char);
            last_Char = t.getSquare(r,c)+1;
            col_loc++;
            t.setSquare(row_loc, col_loc, arr_Char);
          }
        }
      }
      // Check if move is down
      else if(ran == 3)
      {
        if(!t.isWall(r+1,c) && !t.isExit(r+1, c))
        {
          if(t.isSpace(r+1, c) || t.isRoot(r+1, c) || t.isCop(r+1, c))
          {
            if(t.isCop(r+1,c))
              is_Caught = true;
            t.setSquare(r, c, last_Char);
            last_Char = t.getSquare(r+1,c);
            row_loc++;
            t.setSquare(row_loc, col_loc, arr_Char);
          }
        }
      }
      // Check if move is left
      else if(ran == 4)
      {
        if(!t.isWall(r,c-1) && !t.isExit(r,c-1))
        {
          if(t.isSpace(r, c-1) || t.isRoot(r, c-1) || t.isCop(r, c-1))
          {
            if(t.isCop(r,c-1))
              is_Caught = true;
            t.setSquare(r, c, last_Char);
            last_Char = t.getSquare(r,c-1);
            col_loc--;
            t.setSquare(row_loc, col_loc, arr_Char);
          }
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

  // loop to ensure he is placed on a space
  while(!placed)
  {
    randCol = myRand(t.getSize()-1, 0);
    randRow = myRand(t.getSize()-1, 0);
    if(t.getSquare(randRow, randCol) == SPACE)
    {
      t.setSquare(randRow, randCol, arr_Char);
      row_loc = randRow;
      col_loc = randCol;
      placed = true;
    }
  }
  return;
}

char polluter:: getChar()const
{
  return arr_Char;
}

short polluter:: getRow()const
{
  return row_loc;
}

short polluter:: getCol()const
{
  return col_loc;
}
