#pragma once
#include "Ship.h"

class Destroyer : public Ship
{
public:
    Destroyer();
    string getType()const;
    ~Destroyer(){};
};
