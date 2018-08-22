#pragma once
#include "Carrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarine.h"
#include "Destroyer.h"

class Player
{
private:
    char matrix[10][10];
    vector<Ship*> ships;
    vector<string> bussyTanks;
    bool shipSunken;
public:
    bool sunken()const;
    Player();
    ~Player();
    void positionCarrier(vector<Position> pos);
    void positionBattleship(vector<Position> pos);
    void positionCruiser(vector<Position> pos);
    void positionSubmarine(vector<Position> pos);
    void positionDestroyer(vector<Position> pos);
    void getHit(Position pos);
    bool canStrike(string type)const;
    vector<Ship*> getShips()const;
    bool isAlive()const;
    void print()const;
    void print2()const;
    void write(ofstream &out);
    void read(ifstream &in);
    void strike(string type);
};
