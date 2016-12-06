//Programmer: ANDREW BRAY, JOSHUA WARNER        ID: 12518487, 12522483
//Class: CS1570                    Section: A, B
//Date: 11/18/16                   File: hw10.cpp
//Description: CPP file for the homework 10 file, yo

#include "hw10.h"

int main()
{
  short grid_size;
  short num_roots;
  short num_cops;
  short num_days;
  short points_wall;
  short points_cop;
  ifstream fin;
  fin.open(CONFIG_FILE.c_str());

  fin >> grid_size;
  fin >> num_roots;
  fin >> num_cops;
  fin >> num_days;
  fin >> points_wall;
  fin >> points_cop;

  for (short i = 0; i < num_days; i++)
  {

    if (i < 2)
    {
      cout << "Day " << i +1 << ": " << endl;
      simulate(true);
    }
    else
      simulate(false);

  }

  return 0;
}
