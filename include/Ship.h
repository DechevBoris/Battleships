#pragma once
#include "Position.h"

class Ship
{
private:
    int shipSize;
    vector<Position> position;
protected:
    virtual void setShipSize(int s);
public:
     virtual void setPosition(vector<Position> &other);
     Ship& operator=(const Ship& other);
     virtual ~Ship(){};
     virtual void getHit(Position pos);
     int getShipSize()const;
     vector<Position> getPosition()const;
     virtual string getType()const = 0;
     virtual void write(ofstream& out);
     virtual void read(ifstream& in);
     virtual bool isFloating()const;
};
