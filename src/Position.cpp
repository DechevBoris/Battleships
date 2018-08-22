#include "Position.h"

Position::Position()
{
    this->horizontal = 0;
    this->vertical = 0;
    this->occupied = false;
    this->down = false;
}

Position::Position(int h, int v)
{
    this->horizontal = h;
    this->vertical = v;
    this->occupied = false;
    this->down = false;
}

Position& Position::operator=(const Position& other)
{
    if(this != &other)
    {
        this->horizontal = other.horizontal;
        this->vertical = other.vertical;
        this->occupied = other.occupied;
        this->down = other.down;
    }
    return *this;
}

bool Position::operator==(const Position other)
{
    return (this->horizontal == other.getHorizontal() &&
            this->vertical == other.getVertical());
}

void Position::setHorizontal(int h){this->horizontal = h;}

void Position::setVertical(int v){this->vertical = v;}

void Position::occupy(){this->occupied = true;}

void Position::putDown(){this->down = true;}

int Position::getHorizontal()const{return this->horizontal;}

int Position::getVertical()const{return this->vertical;}

bool Position::isOccupied()const{return this->occupied;}

bool Position::isDown()const{return this->down;}

void Position::print()const
{
    cout << "horizontal: " << this->horizontal << endl;
    cout << "vertical: " << this->vertical << endl;
    cout << "isOccupied: " << this->occupied << endl;
    cout << "isDown: " << this->down << endl;
}

bool Position::isValidPosition()const
{
    return (this->horizontal >= 0 && this->horizontal < 10 &&
            this->vertical >= 0 && this->vertical < 10);
}

void Position::write(ofstream& out)
{
    out << this->horizontal;
    out << this->vertical;
    out << this->occupied;
    out << this->down;
}

void Position::read(ifstream &in)
{
    in >> this->horizontal;
    in >> this->vertical;
    in >> this->occupied;
    in >> this->down;
}
