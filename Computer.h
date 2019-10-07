#pragma once
#include <string>
using namespace std;
class Computer
{
public:
	Computer();
	Computer(char cpu_choice_arg);
	void make_choice(string playStyle, char perdiction);
	char get_cpu_choice();
	virtual ~Computer();
private:
	char cpu_choice;
};

