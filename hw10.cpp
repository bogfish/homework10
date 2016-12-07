//Programmer: ANDREW BRAY, JOSHUA WARNER        ID: 12518487, 12522483
//Class: CS1570                    Section: A, B
//Date: 11/18/16                   File: hw10.cpp
//Description: CPP file for the homework 10 file

#include "hw10.h"

int main()
{
  short grid_size;  // Town grid size
  short num_roots;  // Number of roots to place
  short num_cops;   // Number of cops
  short num_days;   // Number of days
  short points_wall;// Points lost for wall
  short points_cop; // Points lost for cop
  // ifstream declaration and connect
  ifstream fin;
  fin.open(CONFIG_FILE.c_str());

  // Statistics variables
  short numWin = 0;
  short numExit = 0;
  short numDigLose = 0;
  short numRootLose = 0;
  float sumTox = 0;
  float pcntWin;
  float pcntRoot;
  float pcntDig;
  float pcntExit;
  float avgTox;

  // Seed random number generator
  srand(time(NULL));

  // Get numbers from config.dat
  fin >> grid_size;
  fin >> num_roots;
  fin >> num_cops;
  fin >> num_days;
  fin >> points_wall;
  fin >> points_cop;

  // Simulation
  for (short i = 0; i < num_days; i++)
  {
    // Check for print
    if (i < 2)
    {
      // Output first x number of days
      cout << "Day " << i + 1 << ": " << endl;
      simulate(true, numWin, numExit, numDigLose, numRootLose, sumTox);
    }
    else
      // do the rest of the simulation
      simulate(false, numWin, numExit, numDigLose, numRootLose, sumTox);
  }

  // Calculate percents
  pcntWin = static_cast<float>(numWin) / static_cast<float>(num_days) *100;
  pcntRoot = static_cast<float>(numRootLose) / num_days * 100;
  pcntDig = static_cast<float>(numDigLose) / num_days * 100;
  pcntExit = static_cast<float>(numExit) / num_days * 100;
  avgTox = sumTox / num_days;
  fin.close();

  // Output statistics
  cout<<"-----STATISTICS-----"<<endl;
  cout<<"Percentage of wins: "<< pcntWin << "%" << endl;
  cout<<"Percentage of activist exits: "<< pcntExit << "%" << endl;
  cout<<"Percentage of times the activist got stoned out of their mind: "
      << pcntRoot << "%" << endl;
  cout<<"Percentage of times the activist died from dignity loss, and then "
        "rose from the dead, like some kind of teenager Jesus: "
      << pcntDig << "%" << endl;
  cout<<"The activist's average toxicity: "<<avgTox<<endl;

  return 0;
}
