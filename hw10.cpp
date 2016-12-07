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

  short numWin = 0;
  short numExit = 0;
  short numDigLose = 0;
  short numRootLose = 0;
  float sumTox = 0;
  float pcntWin;
  float avgTox;

  srand(time(NULL));

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
      cout << "Day " << i + 1 << ": " << endl;
      simulate(true, numWin, numExit, numDigLose, numRootLose, sumTox);
    }
    else
      simulate(false, numWin, numExit, numDigLose, numRootLose, sumTox);
  }

  pcntWin = static_cast<float>(numWin) / static_cast<float>(num_days) *100;
  avgTox = sumTox / num_days;
  fin.close();
  cout<<"-----STATISTICS-----"<<endl;
  cout<<"Percentage of wins: %"<<pcntWin<<endl;
  cout<<"Number of times the activist exited: "<<numExit<<endl;
  cout<<"Number of times the activist got stoned out of their mind: "
      <<numRootLose<<endl;
  cout<<"Number of times the activist died from dignity loss, and then "
        "rose from the dead, like some kind of teenager Jesus: "
      <<numDigLose<<endl;
  cout<<"The activist's average toxicity: "<<avgTox<<endl;

  return 0;
}
