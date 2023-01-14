#include "Team.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

	Team::Team(string newName, string newRegion, string newSeed) {
		name=newName;
		region=newRegion;
		seed = newSeed;
		numWins =0;
		
	}

	Team::Team() {
		name="";
		region="";
		seed="";
		numWins = 0;
	}
	
	
	
	
