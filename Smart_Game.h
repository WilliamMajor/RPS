#pragma once
#include "Computer.h"
using namespace std;
class Smart : public Computer
{
public:
    Smart();
    virtual ~Smart();
    void make_choice(map <string, int> gameHistory, string last5Arg);//char prediction
    void make_choice();
};
