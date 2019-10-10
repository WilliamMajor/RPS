
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

char Computer::get_cpu_choice()
{
	return cpu_choice;
}


Computer::~Computer()
{
}
