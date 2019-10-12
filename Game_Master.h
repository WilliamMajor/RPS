#pragma once
#include <map>
#include <string>
using namespace std;
class Game_Master
{
public:
	Game_Master();
	Game_Master(int game_counter_arg);
	void print_game_counter();
	void save_temp_data();
	void get_temp_data();
	int get_game_counter();
	void inc_game_counter();
	void reset_game_counter();
	void addData(string addArg);
	void storeData();
	void retrieveData();
	map<string, int> getgameHistory();
	virtual ~Game_Master();
private:
	int game_counter;
	map<string, int> gameHistory;
};

