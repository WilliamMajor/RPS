#include "Smart_Game.h"
#include "Computer.h"
using namespace std;


Smart::Smart()
{
    
}
void Smart::make_choice(map<string, int> gameHistory,string last5Arg )//char prediction
{
    //cpu_choice = prediction;
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
		case 'r': cpu_choice = 'p';
			break;
		case 'p': cpu_choice = 's';
			break;
		default: cpu_choice = 'r';
			break;
		}
		//cout << "string for found for prediction:" << max->first << " Prediction: " << choice << endl;
	}
	else
	    cpu_choice = rand() % 3;
	    switch (cpu_choice)
	    {
	    case 0: cpu_choice = 'r';
	        break;
	    case 1: cpu_choice = 'p';
	        break;
	    case 2: cpu_choice = 's';
	        break;
	    }; //we dont have enough data from the current session to make a prediction so return x to indicate we need a random generated choice still



}
void Smart::make_choice()
{
}
Smart::~Smart()
{

}
