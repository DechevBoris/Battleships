#pragma once
#include "Player.h"
#include <cstdlib>
#include <ctime>

class Game
{
private:
    Player player;
    Player bot;
    vector<Position> busyPositions;
    int both;
    int botv;
    bool noError;
    bool botSunken;
    bool playerSunken;
public:
    Game();
    void playerPositioning(vector<Position> car, vector<Position> bat,
                           vector<Position> cru, vector<Position> sub,
                           vector<Position> des);
    void botPositioning();
    bool areCoordinatesCorrect(vector<Position> pos)const;
    bool isBusyPosition(Position pos);
    void playerTurn(string type, Position pos);
    void botTurn();
    void print()const;
    bool areBothAlive()const;
    void write();
    void read();
};
