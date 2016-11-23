//Programmer: ANDREW BRAY          ID: 12518487
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: town.cpp
//Description: Function file for the town class


#include "town.h"

void town:: build()
{
  short halfSize = size / 2;//Used to place exits
  for(int r = 0; r < size; r++)
  {
    for(int c = 0; c < size; c++)
    {
      if(((r==0||r==size-1) && c==halfSize) || //Adds exits
         ((c==0||c==size-1) && r==halfSize))
         townMap[r][c] = EXIT;
     else if(r==0 || r==size-1 || c==0 || c==size-1)//Adds walls
        townMap[r][c] = WALL;
      else
        townMap[r][c] = ' ';//Fils rest of town with blank space
    }
  }
  return;
}

void town:: clear()
{
  for(int r = 0; r < MAX_SIZE; r++)
    for(int c = 0; c < MAX_SIZE; c++)
      townMap[r][c] = ' ';
  return;
}

short town:: getSize()const
{
  return size;
}


ostream& operator<<(ostream & out, const town & T)
{
  for(int r = 0; r < T.size; r++)
  {                               //Outputs the town like this
    for(int c = 0; c < T.size; c++)//    | c | c |
      cout<<"| "<<T.townMap[r][c]<<" ";//| c | c |
    cout<<"|"<<endl;
  }
  return out;
}

bool town:: isWall(const char check)const
{
  return check==WALL ? true : false;
}

bool town:: isExit(const char check)const
{
  return check==EXIT ? true : false;
}

char town:: getSquare(const short row, const short col)const
{
  return townMap[row][col];
}

void town:: setSquare(const short row, const short col, const char val)
{
  townMap[row][col] = val;
  return;
}
