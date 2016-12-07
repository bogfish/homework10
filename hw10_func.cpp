#include "hw10.h"

void simulate(const bool print, short & numWin, short & numExit,
              short & numDigLose, short & numRootLose, float & sumTox)
{
  // Town specifics
  short grid_size;
  short num_roots;
  short num_cops;
  short num_days;
  short points_wall;
  short points_cop;

  // Connect file and get contents
  ifstream fin;
  fin.open(CONFIG_FILE.c_str());

  fin >> grid_size;
  fin >> num_roots;
  fin >> num_cops;
  fin >> num_days;
  fin >> points_wall;
  fin >> points_cop;

  // Declare town, activist, and polluter
  town Springfield(grid_size, num_roots, num_cops);
  activist Lisa("Lisa", 'L', points_wall, points_cop);
  polluter Homer("Homer", 'H');

  // Place activist and polluter
  Lisa.placeMeInMiddle(Springfield);
  Homer.place_me(Springfield);

  // Run simulation for a day
  while(!Lisa.getWin() && !Lisa.getLose())
  {
    // Random move
    Homer.random_move(Springfield);
    if(print)
    {
      // Output springfield
      cout<<Springfield;
      usleep(SLEEP);//Makes the compiler wait .45 seconds before printing
                     //for readability purposes
    }
    // compares the states, returns 0 if equal, hence the !
    if(!STATES[0].compare(Lisa.getState()))
    {
      // Search for homer
      Lisa.searchMove(Springfield, Homer);
      if(print)
      {
        // Output springfield
        cout<<Springfield;
        usleep(SLEEP);
      }
    }
    // Check state
    else if (!STATES[1].compare(Lisa.getState()))
    {
      // Randmove
      Lisa.randMove(Springfield);
      if(print)
      {
        cout<<Springfield;
        usleep(SLEEP);
      }
    }
  }

  if (print)
  {
    // Output stats of Lisa for that day
    cout << Lisa;
    sleep(2);
  }
  if(Lisa.getWin())
    numWin++;
  else
  {
    if(!STATES[2].compare(Lisa.getState()))
      numRootLose++;
    else if(Lisa.getDignity() <= MIN_DIG)
      numDigLose++;
    else
      numExit++;
  }
  sumTox += Lisa.getTox();

  // Close file
  fin.close();
  return;
}
