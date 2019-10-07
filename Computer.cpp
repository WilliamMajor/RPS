
#include "Computer.h"
#include <stdlib.h>
#include <string>
using namespace std;

Computer::Computer()
{
}

Computer::Computer(char cpu_choice_arg)
{
	cpu_choice = cpu_choice_arg;
}

void Computer::make_choice(string playStyle, char perdiction)
{
	if(playStyle == "-s")
		cpu_choice = perdiction;
	if(playStyle == "-r" || cpu_choice == 'x') // cpu choice will be x if the prediction passed into as an argument does not have enough data on the user to give a prediction
	{
		cpu_choice = rand() % 3;
		switch (cpu_choice)
		{
		case 0: cpu_choice = 'r';
			break;
		case 1: cpu_choice = 'p';
			break;
		case 2: cpu_choice = 's';
			break;
		}
	}
	//even if we have chosen random we will not change any of the other code, there is no point not collecting data on the users paterns even if we aren't trying to win.
}

char Computer::get_cpu_choice()
{
	return cpu_choice;
}


Computer::~Computer()
{
}
