#pragma once
#include <string>
using namespace std;
class Computer //This will be my duck
{
public:
	Computer();
	Computer(char cpu_choice_arg);
	virtual void make_choice(char perdiction) = 0;
	virtual void make_choice() = 0;
	char get_cpu_choice();
	virtual ~Computer();
protected:
	char cpu_choice;
};

