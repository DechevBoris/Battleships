#pragma once
#include "Ship.h"

class Cruiser : public Ship
{
public:
    Cruiser();
    string getType()const;
    ~Cruiser(){};
};
