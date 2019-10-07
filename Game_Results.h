#pragma once
using namespace std;
class Game_Results
{
public:
	Game_Results();
	Game_Results(int cpu_wins_arg, int user_wins_arg);

	void calc_game_results(char cpu_choice, char user_choice);
	void print_win_record(int gamesPlayed);
	void addToLast5(char cpuChoice, char userChoice);
	string getLast5();
	virtual ~Game_Results();

private:
	int cpuWins;
	int userWins;
	string last5;	
	
};

