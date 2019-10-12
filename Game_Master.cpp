#include "Game_Master.h"
#include <iostream>
#include <stdio.h>
#include <iterator>
#include <fstream>
#include <map>

using namespace std;


Game_Master::Game_Master()
{
	game_counter = 0;
}

Game_Master::Game_Master(int game_counter_arg)
{
	game_counter = game_counter_arg;
}

void Game_Master::print_game_counter()
{
	cout << game_counter << endl;
}

int Game_Master::get_game_counter()
{
	return game_counter;
}

void Game_Master::inc_game_counter()
{
	game_counter++;
}

void Game_Master::reset_game_counter()
{
	game_counter = 0;
}

void Game_Master::addData(string addDataArg)
{
	map<string, int>::iterator itr;
	itr = gameHistory.find(addDataArg);
	if(itr == gameHistory.end()) //if we havent seen this combo of the last 5 choices place it into the dict
	{
		gameHistory.insert(pair<string, int>(addDataArg, 0));
		itr = gameHistory.find(addDataArg);
	}
	else//increment the number of times that string has been seen
		itr->second++;
}

void Game_Master::storeData()
{
	map<string, int>::iterator itr;
	ofstream gameData;
  	gameData.open ("gamedata.txt");
	for (itr = gameHistory.begin(); itr != gameHistory.end(); ++itr)//for all entries in the dictionary place it in the file
		gameData << itr->first << "," << itr->second << endl;
		
	gameData.close();
}

void Game_Master::retrieveData()
{
	ifstream storedGameData;
	string dataPoint, count;
	storedGameData.open("gamedata.txt");
	while(getline(storedGameData, dataPoint, ','))
	{
		getline(storedGameData, count);
		gameHistory.insert(pair<string, int> (dataPoint, stoi(count)));
	}
	storedGameData.close();
}



map<string, int> Game_Master::getgameHistory()
{
	return gameHistory;
}

Game_Master::~Game_Master()
{
}
