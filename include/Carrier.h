#pragma once
#include "Ship.h"

class Carrier : public Ship
{
public:
    Carrier();
    string getType()const;
    ~Carrier(){};
};
