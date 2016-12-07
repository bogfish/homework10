#include "hw10.h"

void simulate(const bool print)
{
  short grid_size;
  short num_roots;
  short num_cops;
  short num_days;
  short points_wall;
  short points_cop;

  // short current_day = 1;
  ifstream fin;
  fin.open(CONFIG_FILE.c_str());

  fin >> grid_size;
  fin >> num_roots;
  fin >> num_cops;
  fin >> num_days;
  fin >> points_wall;
  fin >> points_cop;

  town Springfield(grid_size, num_roots, num_cops);
  activist Lisa("Lisa", 'L', points_wall, points_cop);
  polluter Homer("Homer");

  Homer.place_me(Springfield);
  Lisa.placeMeInMiddle(Springfield);

  while(!Lisa.getWin() && !Lisa.getLose() && !Homer.getWin())
  {
    Homer.random_move(Springfield);
    if(print)
    {
      cout<<Springfield;
      usleep(SLEEP);//Makes the compiler wait .45 seconds before printing
                     //for readability purposes
    }
    // compares the states, returns 0 if equal, hence the !
    if(!STATES[0].compare(Lisa.getState()))
    {
      Lisa.searchMove(Springfield, Homer);
      if(print)
      {
        cout<<Springfield;
        usleep(SLEEP);
      }
    }
    else if (!STATES[1].compare(Lisa.getState()))
    {
      Lisa.randMove(Springfield);
      if(print)
      {
        cout<<Springfield;
        usleep(SLEEP);
      }
    } else if (!STATES[2].compare(Lisa.getState()))
    {
      break;
    }
  }

  if (print)
  {
    cout << Lisa;
    sleep(2);
  }

  return;
}
