#include <iostream>
#include "User.h"
#include "Game_Master.h"
#include "Computer.h"
#include "Game_Results.h"

using namespace std;


int main(int argc, char** argv) {
	Game_Master Master;
	Computer CPU;
	User Pro_Gamer;
	Game_Results * Results;

	Master.retrieveData();
	while (Pro_Gamer.get_user_choice() != 'q') //check to see if the user has prompted a quit
	{
		Results = new Game_Results(); //make a new game results object only when the user requests it or if it is the first time.
		while (true) //sit in the inner loop while game is being played
		{
			CPU.make_choice(argv[1], Master.makePerdiction(Results->getLast5()));
			Pro_Gamer.make_choice();
			if (Pro_Gamer.get_user_choice() == 'n' || Pro_Gamer.get_user_choice() == 'q')// if we get a quit or new game option we break out of the inner loop
			{
				cout << endl << endl << endl;
				break;
			}
			Results->calc_game_results(CPU.get_cpu_choice(), Pro_Gamer.get_user_choice());
			Results->addToLast5(Pro_Gamer.get_user_choice(), CPU.get_cpu_choice());
			Results->print_win_record(Master.get_game_counter());
			if((Results->getLast5().size()) >= 5)
			{
				Master.addData(Results->getLast5());
				Master.storeData();
			}
			Master.inc_game_counter();																																																// of it once we store the results, maybe a previous games object and a current game object?
		}
		Master.reset_game_counter(); // if a new session is requested we want to reset the amount of games played....although I could see keeping a long term games played to track how much learning the cpu has done
		delete Results; //whether we are quiting or just creating a new session we can now delete the current game results object, as we will be replacing it in the next session.
		
	}
	
	cout << "GAME OVER" << endl << endl << endl;

	return 0;
}
