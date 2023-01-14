#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include "Team.h"
#include "Parser.h"
using namespace std;

Team playGame(Team& one, Team& two);
Team Tourney(vector<Team>& tournament, int numTeams, vector<Team>& tournament2, int size);


int main(int argc, char *argv[]) {
	
	ifstream fin;
	vector<Team> tournament;
	string newTeam;
	Team winner;
	int numTeams=0;
	
	if(argc >=2){
		
		fin.open(argv[1]);
	
		while(getline(fin,newTeam,'\n')){
			Parser line(newTeam);	
			
			Team temp(line.getOperation(),line.getArg1(),line.getArg2());
			tournament.push_back(temp);
			numTeams++;
		}
		
		
		if (ceil(log2(numTeams)) == floor(log2(numTeams))){
			cout <<  "------------" << endl << 
						"Tournament:" << endl << 
						"------------" << endl;
			winner = Tourney(tournament, numTeams,tournament,numTeams);
				
			cout <<  "------------" << endl <<
						"Winner:" << endl << 
						"------------" << endl;
			cout << winner.getName() << " (" << winner.getRegion() << " " << winner.getSeed() << 
				") [" << winner.getWins() << " wins] is the winner!" << endl;
	
			cout <<  "------------" << endl <<
						"Stats:" << endl << 
						"------------" << endl;
			for (int i=0; i<numTeams; i++){
				cout << tournament[i].getName() << " (" << tournament[i].getRegion() << " " << tournament[i].getSeed() << 
				") [" << tournament[i].getWins() << " wins]" << endl;
			}
	
				
		}
		else{
			cout << "File must include a number of teams that is a power of 2" << endl <<
						"(There are " << numTeams << " teams in file " << argv[1] <<")" << endl;	
		}

		fin.close();
	}
	
	return 0;
}

Team playGame(Team& one, Team& two){
	string temp1 = one.getName();
	string temp2 = two.getName();
	int length=0;
	
	if (temp1.length() < temp2.length()){length = temp1.length();}
	else {length = temp2.length();}
	
	for (int i =0; i <length; i++){
		if (temp1[i] > temp2[i]){
			two.weWin();
			//for(int i=0; i<size; i++){if(one.getName()==tournament[i].getName()){tournament[i].weWin();}}
			cout << two.getName() << " (" << two.getRegion() << " " << two.getSeed() << ") [" << two.getWins() << " wins] defeats " <<
				one.getName() << " (" << one.getRegion() << " " << one.getSeed() << ") [" << one.getWins() << " wins]" << endl;
			return two;		
		}	
		if (temp1[i] < temp2[i]){
			one.weWin();
			//for(int i=0; i<size; i++){if(one.getName()==tournament[i].getName()){tournament[i].weWin();}}
			cout << one.getName() << " (" << one.getRegion() << " " << one.getSeed() << ") [" << one.getWins() << " wins] defeats " <<
				two.getName() << " (" << two.getRegion() << " " << two.getSeed() << ") [" << two.getWins() << " wins]" << endl;
			return one;
		}
	}
	return one;
}

Team Tourney(vector<Team>& tournament, int numTeams, vector<Team>& tournament2, int size){
	vector<Team> temp1;
	vector<Team> temp2;
	
	if (numTeams ==2){
		return playGame(tournament[0],tournament[1]);	
	}
	
	for(int i =0; i < numTeams/2; i++){
		temp1.push_back(tournament[i]);	
	}
	for(int i = numTeams/2; i <numTeams; i++){
		temp2.push_back(tournament[i]);	
	}
	
	
	Team winner1 = Tourney(temp2, numTeams/2, tournament2, size);
	Team winner2 = Tourney(temp1, numTeams/2, tournament2, size);
	
	return playGame(winner1,winner2);
	
	
}




