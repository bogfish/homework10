//Programmer: ANDREW BRAY          ID: 12518487
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: activist.cpp
//Description: Function file for the activist class

#include "activist.h"

void activist:: placeMeInMiddle(town & t)
{
  short halfSize = t.getSize()/2;
  row_loc = halfSize;
  col_loc = halfSize;
  t.setSquare(row_loc, col_loc, arr_Char);
  return;
}

void activist:: randMove(town & t)
{
  short ran;//Will be used to generate number 1 - 4 to represent movement
                         //  1
                         //4 A 2
                         //  3
  short r = row_loc;//Because I'm too lazy to type row_loc and col_loc
  short c = col_loc;
  bool done = false;//Checks to see if the activist was able to move
  char currentSquare; //To be used to set the square in the town map. NOT USED
  ran = myRand(4,1);
  if(ran == 1)
  {
    if(!t.isWall(r-1,c) && !t.isExit(r-1,c))
    {
      t.setSquare(r, c, last_Char);
      row_loc--;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  else if(ran == 2)
  {
    if(!t.isWall(r,c-1) && !t.isExit(r,c-1))
    {
      t.setSquare(r, c, last_Char);
      col_loc--;
      t.setSquare(r, col_loc, arr_Char);
    }
  }
  else if(ran == 3)
  {
    if(!t.isWall(r+1,c) && !t.isExit(r+1,c))
    {
      t.setSquare(r, c, last_Char);
      row_loc++;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  else if(ran == 4)
  {
    if(t.isWall(r,c-1))
    {
      //DO WALL STUFF
    }
    else if(t.isExit(r,c-1))
    {
      //DO EXIT STUFF
    }
    else
    {
      if(t.isCop(r,c-1))
      {
        //DO COP STUFF
      }
      t.setSquare(r, c, last_Char);
      col_loc--;
      last_Char = t.getSquare(row_loc, col_loc);
      t.setSquare(row_loc, col_loc, arr_Char);
    }
    if(!t.isWall(r,c-1) && !t.isExit(r,c-1))
    {
      t.setSquare(r, c, last_Char);
      col_loc--;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  return;
}

void activist:: searchMove(town & t, const polluter & p)
{
  if(p.getRow() > row_loc)
  {
    t.setSquare(row_loc, col_loc, last_Char);
    row_loc++;
    t.setSquare(row_loc, col_loc, arr_Char);
  }
  else if(p.getRow() < row_loc)
  {
    t.setSquare(row_loc, col_loc, last_Char);
    row_loc--;
    t.setSquare(row_loc, col_loc, arr_Char);
  }
  else if(p.getCol() > col_loc)
  {
    t.setSquare(row_loc, col_loc, last_Char);
    col_loc++;
    t.setSquare(row_loc, col_loc, arr_Char);
  }
  else if(p.getCol() < col_loc)
  {
    t.setSquare(row_loc, col_loc, last_Char);
    col_loc--;
    t.setSquare(row_loc, col_loc, arr_Char);
  }
  return;
}

ostream& operator<<(ostream & out, const activist & A)
{
  cout<<"Activist: "<<A.name<<endl<<"Dignity: "<<A.dignity<<endl
      <<"Toxicity: "<<A.toxicity<<endl<<"Row: "<<A.row_loc<<endl
      <<"Column: "<<A.col_loc<<endl;
  return out;
}


short myRand(const short max, const short min)
{
  short retVal;
  retVal = rand() % (max - min +1) + min;
  return retVal;
}
