//Programmer: ANDREW BRAY, JOSHUA WARNER          ID: 12518487, 12522483
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: town.cpp
//Description: Function file for the town class


#include "town.h"

void town:: build()
{
  short rootCount = 0;//These two are used to stop the array from placing too
  short copCount = 0; //many cops or roots
  short randRow;//These two are used to find a random tile to put the cops and
  short randCol;//roots into.

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
        townMap[r][c] = SPACE;//Fils rest of town with blank space
    }
  }


  //This loop will place the cop and root symbols in the array
  while(rootCount < num_roots && copCount < num_cops)
  {
    randRow = myRand(size-1, 1);//myRand is called for size-1 and 1 to prevent
    randCol = myRand(size-1, 1);//choosing a square with an exit or wall
    if(getSquare(randRow, randCol) == SPACE)
    {
      if(copCount < num_cops)
      {
        copCount++;
        townMap[randRow][randCol] = COP;
      }
      else
      {
        rootCount++;
        townMap[randRow][randCol] = ROOT;
      }
    }
  }
  return;
}

void town:: clear()
{
  for(int r = 0; r < MAX_SIZE; r++)
    for(int c = 0; c < MAX_SIZE; c++)
      townMap[r][c] = SPACE;
  return;
}

void town:: setSize(const short s)
{
  if(s < MAX_SIZE || s < 1)
    size = s;
  else
    size = MAX_SIZE;
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

bool town:: isWall(const short row, const short col)const
{
  return townMap[row][col]==WALL ? true : false;
}

bool town:: isExit(const short row, const short col)const
{
  return townMap[row][col]==EXIT ? true : false;
}

bool town:: isCop(const short row, const short col)const
{
  return townMap[row][col]==COP ? true : false;
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

short myRand(const short max, const short min)
{
  short retVal;
  retVal = rand() % (max - min +1) + min;
  return retVal;
}
