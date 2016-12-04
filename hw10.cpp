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
  town Springfield;
  ifstream fin;
  fin.open(CONFIG_FILE.c_str());

  if (fin.is_open())
  {
    cout << "File was opened!" << endl;
  } else
  {
    cout << "Nah, son" << endl;
  }
  return 0;
}
