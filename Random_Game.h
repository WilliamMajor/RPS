#pragma once
#include "Computer.h"
using namespace std;

class Random : public Computer
{
public:
    Random ();
    virtual ~Random();
    void make_choice();
    void make_choice(map<string,int>gameHistory, string last5Arg);
};
