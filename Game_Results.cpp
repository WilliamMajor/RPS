#include <iostream>
#include "Game_Results.h"


using namespace std;

//game results database will be added to game_master at a later date

Game_Results::Game_Results()
{
	cpuWins = 0;
	userWins = 0;
}

Game_Results::Game_Results(int cpuWinsArg, int userWinsArg) // there is no use for this constructor yet, but it may be useful to have this if we to load win history from previous sessions
{
	cpuWins = cpuWinsArg;
	userWins = userWinsArg;
}

void Game_Results::calc_game_results(char cpu_choice, char user_choice)
{
	if (cpu_choice == user_choice)
	{
		cout << cpu_choice << " <= cpu, user => " << user_choice << endl;
		cout << "TIE" << endl << endl;
	}
		
	else if ((cpu_choice == 'r' && user_choice == 'p') ||
		(cpu_choice == 'p' && user_choice == 's') ||
		(cpu_choice == 's' && user_choice == 'r'))
	{
		userWins++;
		cout << cpu_choice << " <= cpu, user => " << user_choice << endl;
		cout << "YOU WIN" << endl << endl;
	}
	else
	{
		cpuWins++;
		cout << cpu_choice << " <= cpu, user => " << user_choice << endl;
		cout << "YOU LOSE" << endl << endl;
	}
}
void Game_Results::print_win_record(int gamesPlayed)
{
	cout << "User Wins: " << userWins << endl;
	cout << "Computer Wins: " << cpuWins << endl;
	cout << "Games Played: " << gamesPlayed << endl << endl;
 }
string Game_Results::getLast5()
{
	return last5;
}
void Game_Results::addToLast5(char cpuChoice, char userChoice)
{
	last5 += cpuChoice;
	last5 += userChoice;
	while((int)last5.size() > 5)
		last5.erase(0,1); //if last 5 is currently full remove the oldest two entries
}

Game_Results::~Game_Results()
{
}
