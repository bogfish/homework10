//Programmer: ANDREW BRAY, JOSHUA WARNER          ID: 12518487, 12522483
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
  ran = myRand(4,1);

  if(ran == 1)
  {
    if(t.isWall(r-1,c))
    {
      dignity -= wall_Loss;
    }
    else if(t.isExit(r-1,c))
    {
      lose = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      if(t.isCop(r-1,c))
      {
        dignity -= cop_Loss;
        t.setSquare(r, c, last_Char);
        last_Char = COP;
      }
      else if(t.isRoot(r-1,c))
      {
        //DO ROOT STUFF
        //last_Char will NOT be the root character, as the root will be gone
      }
      row_loc--;
      last_Char = t.getSquare(row_loc, col_loc);
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  else if(ran == 2)
  {
    if(t.isWall(r,c+1))
    {
      dignity -= wall_Loss;
    }
    else if(t.isExit(r,c+1))
    {
      lose = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      if(t.isCop(r,c+1))
      {
        dignity -= cop_Loss;
        t.setSquare(r, c, last_Char);
        last_Char = COP;
      }
      else if(t.isRoot(r,c+1))
      {
        //DO ROOT STUFF
        //last_Char will NOT be the root character, as the root will be gone
      }
      col_loc++;
      last_Char = t.getSquare(row_loc, col_loc);
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  else if(ran == 3)
  {
    if(t.isWall(r+1,c))
    {
      dignity -= wall_Loss;
    }
    else if(t.isExit(r+1,c))
    {
      lose = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      if(t.isCop(r+1,c))
      {
        dignity -= cop_Loss;
        t.setSquare(r, c, last_Char);
        last_Char = COP;
      }
      else if(t.isRoot(r+1,c))
      {
        //DO ROOT STUFF
        //last_Char will NOT be the root character, as the root will be gone
      }
      row_loc++;
      last_Char = t.getSquare(row_loc, col_loc);
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  else if(ran == 4)
  {
    if(t.isWall(r,c-1))
    {
      dignity -= wall_Loss;
    }
    else if(t.isExit(r,c-1))
    {
      lose = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      if(t.isCop(r,c-1))
      {
        dignity -= cop_Loss;
        t.setSquare(r, c, last_Char);
        last_Char = COP;
      }
      else if(t.isRoot(r,c-1))
      {
        //DO ROOT STUFF
        //last_Char will NOT be the root character, as the root will be gone
      }
      col_loc--;
      last_Char = t.getSquare(row_loc, col_loc);
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  return;
}

bool activist:: getWin()const
{
  return win;
}

bool activist:: getLose()const
{
  return lose;
}

string activist:: getState()const
{
  return state;
}

void activist:: searchMove(town & t, const polluter & p)
{
  short r = row_loc;//These variables exist because I, Andrew, am too lazy to
  short c = col_loc;//type row_loc and col_loc over and over again
    //Note: The wall and exit checking are still in there in case there is an
    //error involving the location of the polluter. If the activist hits a wall
    //or exit, then the polluter position is wrong.
  if(p.getRow() > row_loc)
  {
    if(t.isWall(r+1,c))
    {
      dignity -= wall_Loss;
    }
    else if(t.isExit(r+1,c))
    {
      lose = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      if (t.getSquare(r+1, c) == p.getChar())
      {
        win = true;
      }
      else if(t.isCop(r+1,c))
      {
        dignity -= cop_Loss;
        t.setSquare(r, c, last_Char);
        last_Char = COP;
      }
      else if(t.isRoot(r+1,c))
      {
        //DO ROOT STUFF
        //last_Char will NOT be the root character, as the root will be gone
      }
      t.setSquare(row_loc, col_loc, last_Char);

      row_loc++;
      last_Char = t.getSquare(row_loc, col_loc);
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }

  else if(p.getRow() < row_loc)
  {
    if(t.isWall(r-1,c))
    {
      dignity -= wall_Loss;
    }
    else if(t.isExit(r-1,c))
    {
      lose = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      if (t.getSquare(r-1,c) == p.getChar())
      {
        win = true;
      }
      else if(t.isCop(r-1,c))
      {
        dignity -= cop_Loss;
        t.setSquare(r, c, last_Char);
        last_Char = COP;
      }
      else if(t.isRoot(r-1,c))
      {
        //DO ROOT STUFF
        //last_Char will NOT be the root character, as the root will be gone
      }
      t.setSquare(row_loc, col_loc, last_Char);
      row_loc--;
      last_Char = t.getSquare(row_loc, col_loc);
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }

  else if(p.getCol() > col_loc)
  {
    if(t.isWall(r,c+1))
    {
      dignity -= wall_Loss;
    }
    else if(t.isExit(r,c+1))
    {
      lose = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      if (t.getSquare(r, c+1) == p.getChar())
      {
        win = true;
      }
      else if(t.isCop(r,c+1))
      {
        dignity -= cop_Loss;
        t.setSquare(r, c, last_Char);
        last_Char = COP;
      }
      else if(t.isRoot(r,c+1))
      {
        //DO ROOT STUFF
        //last_Char will NOT be the root character, as the root will be gone
      }
      t.setSquare(row_loc, col_loc, last_Char);
      col_loc++;
      last_Char = t.getSquare(row_loc, col_loc);
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }

  else if(p.getCol() < col_loc)
  {
    if(t.isWall(r,c-1))
    {
      dignity -= wall_Loss;
    }
    else if(t.isExit(r,c-1))
    {
      lose = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      if (t.getSquare(r, c-1) == p.getChar())
      {
        win = true;
      }
      else if(t.isCop(r,c-1))
      {
        dignity -= cop_Loss;
        t.setSquare(r, c, last_Char);
        last_Char = COP;
      }
      else if(t.isRoot(r,c-1))
      {
        //DO ROOT STUFF
        //last_Char will NOT be the root character, as the root will be gone
      }
      t.setSquare(row_loc, col_loc, last_Char);
      col_loc--;
      last_Char = ' ';
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }

  //If none of the above conditions were true, then the activist and
  //polluter occupy the same square. Thus, the activist has caught the polluter
  else
    win = true;
  return;
}

ostream& operator<<(ostream & out, const activist & A)
{
  cout<<"Activist: "<<A.name<<endl<<"Dignity: "<<A.dignity<<endl
      <<"Toxicity: "<<A.toxicity<<endl<<"Row: "<<A.row_loc<<endl
      <<"Column: "<<A.col_loc<<endl;
  return out;
}
