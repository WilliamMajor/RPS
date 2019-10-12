#include <iostream>
#include "User.h"
#include "Game_Master.h"
#include "Computer.h"
#include "Game_Results.h"
#include "Smart_Game.h"
#include "Random_Game.h"

using namespace std;

string checkArgumentsExist(char* argument);

int main(int argc, char** argv) {
	Game_Master Master;
	User Pro_Gamer;
	Smart SCPU;
	Random RCPU;
	Game_Results * Results;

	string gametype = checkArgumentsExist(argv[1]);
	
	
	Master.retrieveData();
	while (Pro_Gamer.get_user_choice() != 'q') //check to see if the user has prompted a quit
	{
		Results = new Game_Results(); //make a new game results object only when the user requests it or if it is the first time.
		char cpuChoice;
		while (true) //sit in the inner loop while game is being played
		{
			if (gametype == "-s")
			{
				SCPU.make_choice(Master.getgameHistory(), Results->getLast5());//SCPU.make_choice(Master.makePrediction(Results->getLast5()));
				cpuChoice = SCPU.get_cpu_choice();
			}
				
			else
			{
				RCPU.make_choice();
				cpuChoice = RCPU.get_cpu_choice();
			}
				
			
			
			Pro_Gamer.make_choice();
			if (Pro_Gamer.get_user_choice() == 'n' || Pro_Gamer.get_user_choice() == 'q')// if we get a quit or new game option we break out of the inner loop
			{
				cout << endl << endl << endl;
				break;
			}
			Results->calc_game_results(cpuChoice, Pro_Gamer.get_user_choice());
			Results->addToLast5(Pro_Gamer.get_user_choice(), cpuChoice);
			Master.inc_game_counter();	
			Results->print_win_record(Master.get_game_counter());
			if((Results->getLast5().size()) >= 5)
			{
				Master.addData(Results->getLast5());
				Master.storeData();
			}
		}
		Master.reset_game_counter(); // if a new session is requested we want to reset the amount of games played....although I could see keeping a long term games played to track how much learning the cpu has done
		delete Results; //whether we are quiting or just creating a new session we can now delete the current game results object, as we will be replacing it in the next session.
		
	}
	
	cout << "GAME OVER" << endl << endl << endl;

	return 0;
}

string checkArgumentsExist(char* argument)
{
	string gametype = "";
	if (argument == NULL) //default to the smart version
		gametype = "-s";
	else
		gametype = argument;

	return gametype;
}

