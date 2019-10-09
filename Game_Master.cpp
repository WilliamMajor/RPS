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

char Game_Master::makePerdiction(string last5Arg)
{
	if(last5Arg.size() >= 5)//if we have data of the last 5 games we can make a best guess
	{
		map<string, int>::iterator itr;
		map<string, int>::iterator max;
		bool firstMatch = true;
		char choice;

		for (itr = gameHistory.begin(); itr != gameHistory.end(); ++itr)//for all entries in the dictionary place it in the file
		{
			string temp = itr->first;
			string temp2 = last5Arg;
			temp.erase(3,1);
			temp2.erase(3,1);
			if(temp == temp2)
			{
				if (firstMatch == true)
				{
					max = itr;
					firstMatch = false;
				}
				else if(max->second < itr->second)
					max = itr;
			}
		}
		switch (max->first[3])
		{
		case 'r': choice = 'p';
			break;
		case 'p': choice = 's';
			break;
		default: choice = 'r';
			break;
		}
		//cout << "string for found for prediction:" << max->first << " Prediction: " << choice << endl;
		return choice;
	}
	else
		return 'x'; //we dont have enough data from the current session to make a prediction so return x to indicate we need a random generated choice still

	
}


Game_Master::~Game_Master()
{
}
