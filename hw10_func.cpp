#include "hw10.h"

void simulate(const bool print)
{
  short grid_size;
  short num_roots;
  short num_cops;
  short num_days;
  short points_wall;
  short points_cop;
  short current_day = 1;
  ifstream fin;
  fin.open(CONFIG_FILE.c_str());

  if (fin.is_open())
    cout << "File was opened!" << endl;
  else
    cout << "Nah, son" << endl;

  fin >> grid_size;
  fin >> num_roots;
  fin >> num_cops;
  fin >> num_days;
  fin >> points_wall;
  fin >> points_cop;

  town Springfield(grid_size, num_roots, num_cops);
  cout << Springfield << endl;
  activist Lisa("Lisa", 'L', points_wall, points_cop);
  cout << "Activist created" << endl;
  polluter Homer("Homer");
  cout << "Polluter created" << endl;

  Homer.place_me(Springfield);
  cout << "Homer Placed" << endl;
  Lisa.placeMeInMiddle(Springfield);
  cout << "Lisa Placed" << endl;

  while(!Lisa.getWin() && !Lisa.getLose())
  {
    cout << "Homer's move" << endl;
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
      cout << "Lisa is searching" << endl;
      Lisa.searchMove(Springfield, Homer);
      if(print)
      {
        cout<<Springfield;
        usleep(SLEEP);
      }
    }
    else
    {
      cout << "Lisa is randmoving" << endl;
      Lisa.randMove(Springfield);
      if(print)
      {
        cout<<Springfield;
        usleep(SLEEP);
      }
    }
  }

  return;
}
