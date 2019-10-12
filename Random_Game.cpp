#include "Random_Game.h"
#include "Computer.h"

using namespace std;

Random::Random()
{
}

Random::~Random()
{
}

void Random::make_choice()
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

void Random::make_choice(map<string,int>gameHistory, string last5Arg)
{
}
