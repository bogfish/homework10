//Programmer: ANDREW BRAY, JOSHUA WARNER          ID: 12518487, 12522483
//Class: CS1570                    Section: A
//Date: 11/18/16                   File: activist.cpp
//Description: Function file for the activist class

#include "activist.h"

void activist:: placeMeInMiddle(town & t)
{
  // Get halfway point
  short halfSize = t.getSize()/2;
  // Set row and column to halfSize
  row_loc = halfSize;
  col_loc = halfSize;
  // Place char
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
  // Generate ran
  ran = myRand(4,1);
  // Check if ran is 1 (up)
  if(ran == 1)
  {
    // Check for wall
    if(t.isWall(r-1,c))
    {
      // Dignity checks
      if ((dignity -= wall_Loss) < MIN_DIG)
        dignity = MIN_DIG;
      else
        dignity -= wall_Loss;
    }
    // Check for exit
    else if(t.isExit(r-1,c))
    {
      // Set lose and exited to true
      lose = true;
      exited = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      // Check for cop
      if(t.isCop(r-1,c))
      {
        // Do dignity stuffs
        if ((dignity - cop_Loss) < MIN_DIG)
          dignity = MIN_DIG;
        else
          dignity -= cop_Loss;

      }
      // Check for root
      else if(t.isRoot(r-1,c))
      {
        // Declare root and add effect
        root Root;
          *this += Root;
      }
      // Set square at last location to last_Char
      t.setSquare(row_loc, col_loc, last_Char);
      row_loc--;
      // Check for root
      if (!t.isRoot(row_loc, col_loc))
        last_Char = t.getSquare(row_loc, col_loc);
      else
        last_Char = SPACE;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  // Check if ran is 2 (right)
  else if(ran == 2)
  {
    // Check for wall
    if(t.isWall(r,c+1))
    {
      // Do wall dignity stuffs
      if ((dignity -= wall_Loss) < MIN_DIG)
        dignity = MIN_DIG;
      else
        dignity -= wall_Loss;
    }
    // Check for exit
    else if(t.isExit(r,c+1))
    {
      // Set lose and exited to true
      lose = true;
      exited = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      // Check for cop
      if(t.isCop(r,c+1))
      {
        // Do dignity stuffs for cop
        if ((dignity - cop_Loss) < MIN_DIG)
          dignity = MIN_DIG;
        else
          dignity -= cop_Loss;
      }
      // Check for root
      else if(t.isRoot(r,c+1))
      {
        // Do root stuffs
        root Root;
         *this += Root;
      }
      // Set new location and check for last char
      t.setSquare(row_loc, col_loc, last_Char);
      col_loc++;
      if (!t.isRoot(row_loc, col_loc))
        last_Char = t.getSquare(row_loc, col_loc);
      else
        last_Char = SPACE;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  // Check if ran is 3 (down)
  else if(ran == 3)
  {
    // Check for wall
    if(t.isWall(r+1,c))
    {
      // Do wall dignity loss
      if ((dignity -= wall_Loss) < MIN_DIG)
        dignity = MIN_DIG;
      else
        dignity -= wall_Loss;
    }
    // Check for exit
    else if(t.isExit(r+1,c))
    {
      // Set lose to true and exited to true
      lose = true;
      exited = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      // Check for cop
      if(t.isCop(r+1,c))
      {
        // Do cop dignity loss
        if ((dignity - cop_Loss) < MIN_DIG)
          dignity = MIN_DIG;
        else
          dignity -= cop_Loss;
      }
      // Check for root
      else if(t.isRoot(r+1,c))
      {
        // Declare root and add effect
        root Root;
         *this += Root;
      }
      // Set new location
      t.setSquare(row_loc, col_loc, last_Char);
      row_loc++;
      if (!t.isRoot(row_loc, col_loc))
        last_Char = t.getSquare(row_loc, col_loc);
      else
        last_Char = SPACE;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  // Check if ran is 4 (left)
  else if(ran == 4)
  {
    // Check for wall
    if(t.isWall(r,c-1))
    {
      // Do dignity loss
      if ((dignity -= wall_Loss) < MIN_DIG)
        dignity = MIN_DIG;
      else
        dignity -= wall_Loss;
    }
    // Check for exit
    else if(t.isExit(r,c-1))
    {
      // El Activist loses
      lose = true;
      exited = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      // Check for cop
      if(t.isCop(r,c-1))
      {
        // Do dignity loss
        if ((dignity - cop_Loss) < MIN_DIG)
          dignity = MIN_DIG;
        else
          dignity -= cop_Loss;
      }
      // Check for root
      else if(t.isRoot(r,c-1))
      {
        // Add effect
        root Root;
         *this += Root;
      }
      // Set new location
      t.setSquare(row_loc, col_loc, last_Char);
      col_loc--;
      if (!t.isRoot(row_loc, col_loc))
        last_Char = t.getSquare(row_loc, col_loc);
      else
        last_Char = SPACE;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }
  // Check toxicity tiers
  if (toxicity >= SECOND_TOX_UP)
  {
    // RIP activist
    lose = true;
    state = STATES[2];
  } else if (toxicity < FIRST_TOX_UP)
  {
    state = STATES[0];
  }
  if (dignity <= 0)
    lose = true;
  return;
}

// Getter function
bool activist:: getWin()const
{
  return win;
}

// Getter function
bool activist:: getLose()const
{
  return lose;
}

// Getter function
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

  // Check if polluter row is greater
  if(p.getRow() > row_loc)
  {
    // Check for wall
    if(t.isWall(r+1,c))
    {
      // Wall loss
      if ((dignity -= wall_Loss) < MIN_DIG)
        dignity = MIN_DIG;
      else
        dignity -= wall_Loss;
    }
    // Check for exit
    else if(t.isExit(r+1,c))
    {
      // Loser
      lose = true;
      exited = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      // Check for Polluter
      if (t.getSquare(r+1, c) == p.getChar())
      {
        // Activist wins
        win = true;
      }
      // Check for cop
      else if(t.isCop(r+1,c))
      {
        // Do dignity loss
        if ((dignity - cop_Loss) < MIN_DIG)
          dignity = MIN_DIG;
        else
          dignity -= cop_Loss;
      }
      // Check for root
      else if(t.isRoot(r+1,c))
      {
        // Add effect to activist
        root Root;
         *this += Root;
      }
      t.setSquare(row_loc, col_loc, last_Char);
      row_loc++;
      if (!t.isRoot(row_loc, col_loc))
        last_Char = t.getSquare(row_loc, col_loc);
      else
        last_Char = SPACE;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }

  // Check if row is less than current row
  else if(p.getRow() < row_loc)
  {
    // Check for wall
    if(t.isWall(r-1,c))
    {
      // Do dignity loss
      if ((dignity -= wall_Loss) < MIN_DIG)
        dignity = MIN_DIG;
      else
        dignity -= wall_Loss;
    }
    // Check for exit
    else if(t.isExit(r-1,c))
    {
      // Set lose to true
      lose = true;
      exited = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      // Check for polluter
      if (t.getSquare(r-1,c) == p.getChar())
      {
        win = true;
      }
      // Check for cop
      else if(t.isCop(r-1,c))
      {
        // Do dignity loss
        if ((dignity - cop_Loss) < MIN_DIG)
          dignity = MIN_DIG;
        else
          dignity -= cop_Loss;
      }
      // check for root
      else if(t.isRoot(r-1,c))
      {
        root Root;
         *this += Root;
      }
      // Set location
      t.setSquare(row_loc, col_loc, last_Char);
      row_loc--;
      if (!t.isRoot(row_loc, col_loc))
        last_Char = t.getSquare(row_loc, col_loc);
      else
        last_Char = SPACE;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }

  // Check if column is greater than current column
  else if(p.getCol() > col_loc)
  {
    // Check for wall
    if(t.isWall(r,c+1))
    {
      // Do dignity loss
      if ((dignity -= wall_Loss) < MIN_DIG)
        dignity = MIN_DIG;
      else
        dignity -= wall_Loss;
    }
    // Check for exit
    else if(t.isExit(r,c+1))
    {
      lose = true;
      exited = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      // Check for polluter
      if (t.getSquare(r, c+1) == p.getChar())
      {
        win = true;
      }
      // Check for cop
      else if(t.isCop(r,c+1))
      {
        // Dignity loss, you know the drill
        if ((dignity - cop_Loss) < MIN_DIG)
          dignity = MIN_DIG;
        else
          dignity -= cop_Loss;
      }
      // Check for root
      else if(t.isRoot(r,c+1))
      {
        // Root effect
        root Root;
         *this += Root;
      }
      // Set new location
      t.setSquare(row_loc, col_loc, last_Char);
      col_loc++;
      if (!t.isRoot(row_loc, col_loc))
        last_Char = t.getSquare(row_loc, col_loc);
      else
        last_Char = SPACE;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
  }

  // Check if polluter col is less than current col
  else if(p.getCol() < col_loc)
  {
    // Check for wall
    if(t.isWall(r,c-1))
    {
      if ((dignity -= wall_Loss) < MIN_DIG)
        dignity = MIN_DIG;
      else
        dignity -= wall_Loss;
    }
    // check for exit
    else if(t.isExit(r,c-1))
    {
      lose = true;
      exited = true;
      t.setSquare(row_loc, col_loc, last_Char);
    }
    else
    {
      // Check for polluter
      if (t.getSquare(r, c-1) == p.getChar())
      {
        win = true;
      }
      // Check for cop
      else if(t.isCop(r,c-1))
      {
        if ((dignity - cop_Loss) < MIN_DIG)
          dignity = MIN_DIG;
        else
          dignity -= cop_Loss;
      }
      // Check for root
      else if(t.isRoot(r,c-1))
      {
        root Root;
         *this += Root;
      }
      // Set new location
      t.setSquare(row_loc, col_loc, last_Char);
      col_loc--;
      if (!t.isRoot(row_loc, col_loc))
        last_Char = t.getSquare(row_loc, col_loc);
      else
        last_Char = SPACE;
      t.setSquare(row_loc, col_loc, arr_Char);
    }
    // Check toxicity levels
    if (toxicity >= SECOND_TOX_UP)
    {
      lose = true;
      state = STATES[2];
    } else if (toxicity >= FIRST_TOX_UP)
    {
      state = STATES[1];
    }
  }

  //If none of the above conditions were true, then the activist and
  //polluter occupy the same square. Thus, the activist has caught the polluter
  else
    win = true;

  if (dignity <= 0)
    lose = true;

  return;
}

// overloaded output operator
ostream& operator<<(ostream & out, const activist & A)
{
  cout<<"Activist: "<<A.name<<endl<<"Dignity: "<<A.dignity<<endl
      <<"Toxicity: "<<A.toxicity<<endl<<"Row: "<<A.row_loc<<endl
      <<"Column: "<<A.col_loc<<endl;
  return out;
}

// Overloaded += for adding effect
activist activist::operator+=(const root& R)
{
  if ((toxicity += R.getEffect()) > MAX_TOX)
    toxicity = MAX_TOX;
  else if ((toxicity += R.getEffect()) < MIN_TOX)
    toxicity = MIN_TOX;
  else
    toxicity += R.getEffect();

  return *this;
}

// Getter function
float activist:: getTox()const
{
  return toxicity;
}

// Getter function. A real go-getter, in fact.
short activist:: getDignity()const
{
  return dignity;
}
