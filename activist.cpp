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
  short ran;//Will be used to generate number 1 - 8 to represent movement
                         //1 2 3
                         //4 A 5
                         //6 7 8
  short r = row_loc;//Because I'm too lazy to type row_loc and col_loc
  short c = col_loc;
  bool done = false;//Checks to see if the activist was able to move
  do//This entire loop attempts to move the activist
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
