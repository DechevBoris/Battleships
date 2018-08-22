#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Position
{
private:
    int horizontal;
    int vertical;
    bool occupied;
    bool down;
public:
    Position();
    Position(int h, int v);
    Position& operator=(const Position& other);
    bool operator ==(const Position other);
    void setHorizontal(int h);
    void setVertical(int v);
    void occupy();
    void putDown();
    int getHorizontal()const;
    int getVertical()const;
    bool isOccupied()const;
    bool isDown()const;
    void print()const;
    bool isValidPosition()const;
    void write(ofstream &out);
    void read(ifstream &in);
};
