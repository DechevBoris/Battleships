#include "Ship.h"

void Ship::setShipSize(int s)
{
    this->shipSize = s;
}

void Ship::setPosition(vector<Position> &other)
{
    for(size_t i = 0; i < other.size(); i++)
        this->position.push_back(other[i]);
    for(size_t i = 0; i < this->position.size(); i++)
        this->position[i].occupy();
}

Ship& Ship::operator=(const Ship& other)
{
    if(this != &other)
    {
        this->shipSize = other.shipSize;
        vector<Position> tmp = other.getPosition();
        for(size_t i = 0; i < tmp.size(); i++)
            this->position.push_back(tmp[i]);
    }
    return *this;
}

void Ship::getHit(Position pos)
{
    for(size_t i = 0; i < this->position.size(); i++)
        if(this->position[i] == pos)
        {
            this->position[i].putDown();
            this->shipSize--;
        }
}

int Ship::getShipSize()const{return this->shipSize;}

vector<Position> Ship::getPosition()const{return this->position;}

void Ship::write(ofstream& out)
{

    out << this->shipSize;
    for(size_t i = 0; i < this->position.size(); i++)
        this->position[i].write(out);
}

void Ship::read(ifstream& in)
{

    in >> this->shipSize;
    for(size_t i = 0; i < this->position.size(); i++)
    {
        Position tmp;
        tmp.read(in);
        this->position.push_back(tmp);
    }
}

bool Ship::isFloating()const{return this->shipSize > 0;}
