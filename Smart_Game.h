#pragma once
#include "Computer.h"
using namespace std;
class Smart : public Computer
{
public:
    Smart();
    virtual ~Smart();
    void make_choice(char perdiction);
    void make_choice();
};