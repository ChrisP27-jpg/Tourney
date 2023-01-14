#include <iostream>
#include <stdlib.h>
using namespace std;
class Team {
   public:
      Team(string newName, string newRegion, string newSeed);
      Team();
      string getName(){return name;}
      string getRegion(){return region;}
      string getSeed(){return seed;}
      int getWins(){return numWins;}
      void weWin(){numWins++;}
      
   private:
      string name = "";
      string region = "";
      string seed= "";
      int numWins = 0;
};
