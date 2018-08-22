#include "Game.h"

Game::Game()
{
    this->both = 0;
    this->botv = 0;
    this->noError = true;
    this->botSunken = false;
    this->playerSunken = false;
}

void Game::playerPositioning(vector<Position> car, vector<Position> bat,
                             vector<Position> cru, vector<Position> sub,
                             vector<Position> des)
{
    bool flag = true;
    //Valid position check!
    for(size_t i = 0; i < car.size(); i++)
        if(!car[i].isValidPosition())
            flag = false;
    for(size_t i = 0; i < bat.size(); i++)
        if(!bat[i].isValidPosition())
            flag = false;
    for(size_t i = 0; i < cru.size(); i++)
        if(!cru[i].isValidPosition())
            flag = false;
    for(size_t i = 0; i < sub.size(); i++)
        if(!sub[i].isValidPosition())
            flag = false;
    for(size_t i = 0; i < des.size(); i++)
        if(!des[i].isValidPosition())
            flag = false;
    //Straight line check!
    if(!this->areCoordinatesCorrect(car) || !this->areCoordinatesCorrect(bat) ||
       !this->areCoordinatesCorrect(cru) || !this->areCoordinatesCorrect(sub) ||
       !this->areCoordinatesCorrect(des))
        flag = false;

    if(flag)
    {
        bool carFlag = true;
        for(size_t i = 0; i < car.size(); i++)
            if(this->isBusyPosition(car[i]))
                carFlag = false;
        if(carFlag)
        {
            this->player.positionCarrier(car);
            for(size_t i = 0; i < car.size(); i++)
                this->busyPositions.push_back(car[i]);
        }
        else this->noError = false;

        bool batFlag = true;
        for(size_t i = 0; i < bat.size(); i++)
            if(this->isBusyPosition(bat[i]))
                batFlag = false;
        if(batFlag)
        {
            this->player.positionBattleship(bat);
            for(size_t i = 0; i < bat.size(); i++)
                this->busyPositions.push_back(bat[i]);
        }
        else this->noError = false;

        bool cruFlag = true;
        for(size_t i = 0; i < cru.size(); i++)
            if(this->isBusyPosition(cru[i]))
                cruFlag = false;
        if(cruFlag)
        {
            this->player.positionCruiser(cru);
            for(size_t i = 0; i < cru.size(); i++)
                this->busyPositions.push_back(cru[i]);
        }
        else this->noError = false;

        bool subFlag = true;
        for(size_t i = 0; i < sub.size(); i++)
            if(this->isBusyPosition(sub[i]))
                subFlag = false;
        if(subFlag)
        {
            this->player.positionSubmarine(sub);
            for(size_t i = 0; i < sub.size(); i++)
                this->busyPositions.push_back(sub[i]);
        }
        else this->noError = false;

        bool desFlag = true;
        for(size_t i = 0; i < des.size(); i++)
            if(this->isBusyPosition(des[i]))
                desFlag = false;
        if(desFlag)
        {
            this->player.positionDestroyer(des);
            for(size_t i = 0; i < des.size(); i++)
                this->busyPositions.push_back(des[i]);
        }
        else this->noError = false;
    }
    else this->noError = false;
}

void Game::botPositioning()
{
    Position car1(0,0);
    Position car2(0,1);
    Position car3(0,2);
    Position car4(0,3);
    Position car5(0,4);
    vector<Position> car;
    car.push_back(car1);
    car.push_back(car2);
    car.push_back(car3);
    car.push_back(car4);
    car.push_back(car5);
    this->bot.positionCarrier(car);

    Position bat1(0,9);
    Position bat2(1,9);
    Position bat3(2,9);
    Position bat4(3,9);
    vector<Position> bat;
    bat.push_back(bat1);
    bat.push_back(bat2);
    bat.push_back(bat3);
    bat.push_back(bat4);
    this->bot.positionBattleship(bat);

    Position cru1(2,3);
    Position cru2(2,4);
    Position cru3(2,5);
    vector<Position> cru;
    cru.push_back(cru1);
    cru.push_back(cru2);
    cru.push_back(cru3);
    this->bot.positionCruiser(cru);

    Position sub1(3,0);
    Position sub2(4,0);
    Position sub3(5,0);
    vector<Position> sub;
    sub.push_back(sub1);
    sub.push_back(sub2);
    sub.push_back(sub3);
    this->bot.positionSubmarine(sub);

    Position des1(7,6);
    Position des2(7,7);
    vector<Position> des;
    des.push_back(des1);
    des.push_back(des2);
    this->bot.positionDestroyer(des);
}


bool Game::areCoordinatesCorrect(vector<Position> pos)const
{
    bool flag1 = true;
    for(size_t i = 0; i < pos.size() - 1; i++)
        if(pos[i].getHorizontal() != pos[i + 1].getHorizontal())
            flag1 = false;
    bool flag2 = true;
    for(size_t i = 0; i < pos.size() - 1; i++)
        if(pos[i].getVertical() != pos[i + 1].getVertical() + 1)
            flag2 = false;
    bool flag3 = true;
    for(size_t i = 0; i < pos.size() - 1; i++)
        if(pos[i].getVertical() != pos[i + 1].getVertical() - 1)
            flag3 = false;


    bool flag4 = true;
    for(size_t i = 0; i < pos.size() - 1; i++)
        if(pos[i].getVertical() != pos[i + 1].getVertical())
            flag4 = false;
    bool flag5 = true;
    for(size_t i = 0; i < pos.size() - 1; i++)
        if(pos[i].getHorizontal() != pos[i + 1].getHorizontal() + 1)
            flag5 = false;
    bool flag6 = true;
    for(size_t i = 0; i < pos.size() - 1; i++)
        if(pos[i].getHorizontal() != pos[i + 1].getHorizontal() - 1)
            flag6 = false;

    if(!flag1 && !flag4)
        return false;
    if(flag1)
        if(!flag2 && !flag3)
            return false;
    if(flag4)
        if(!flag5 && !flag6)
            return false;
    return true;
}

bool Game::isBusyPosition(Position pos)
{
    for(size_t i = 0; i < this->busyPositions.size(); i++)
        if(pos == this->busyPositions[i])
            return true;
    return false;
}

void Game::playerTurn(string type, Position pos)
{
    this->botSunken = false;
    this->playerSunken = false;
    bool flag = true;
    if(type.compare("carrier") != 0 && type.compare("battleship") != 0 && type.compare("cruiser") != 0 &&
       type.compare("submarine") != 0 && type.compare("destroyer") != 0)
        flag = false;
    if(!pos.isValidPosition())
        flag = false;
    if(!player.canStrike(type))
        flag = false;
    if(flag)
    {
        this->player.strike(type);
        this->bot.getHit(pos);
        if(this->bot.sunken())
            this->botSunken = true;
    }
    else this->noError = false;
}

void Game::botTurn()
{
    this->playerSunken = false;
    this->botSunken = false;
    string car = "carrier";
    string bat = "battleship";
    string cru = "cruiser";
    string sub = "submarine";
    string des = "destroyer";
    vector<string> types;
    types.push_back(car);
    types.push_back(bat);
    types.push_back(cru);
    types.push_back(sub);
    types.push_back(des);
    for(size_t i = 0; i < types.size(); i++)
        if(this->bot.canStrike(types[i]))
        {
            Position pos(this->both, this->botv);
            this->bot.strike(types[i]);
            this->player.getHit(pos);
            if(this->botv == 9)
            {
                this->both++;
                this->botv = -1;
            }
            if(this->both == 9 && this->botv == 9)
            {
                this->both = 0;
                this->botv = -1;
            }
            this->botv++;
            break;
        }
    if(this->player.sunken())
        this->playerSunken = true;
}

//void Game::botTurn()
//{
//    this->playerSunken = false;
//    this->botSunken = false;
//    string car = "carrier";
//    string bat = "battleship";
//    string cru = "cruiser";
//    string sub = "submarine";
//    string des = "destroyer";
//    vector<string> types;
//    types.push_back(car);
//    types.push_back(bat);
//    types.push_back(cru);
//    types.push_back(sub);
//    types.push_back(des);
//    for(size_t i = 0; i < types.size(); i++)
//        if(this->bot.canStrike(types[i]))
//        {
//            srand(time(NULL));
//            this->both = rand() % 10 + 0;
//            this->botv = rand() % 10 + 0;
//            Position pos(this->both,this->botv);
//            this->bot.strike(types[i]);
//            this->player.getHit(pos);
//            break;
//        }
//    if(this->player.sunken())
//        this->playerSunken = true;
//}

void Game::print()const
{
    if(this->noError)
    {
        this->player.print();
        cout << endl;
        if(this->playerSunken)
        {
            cout << "One of your ships have been sunken!\n" << endl;
            if(!this->player.isAlive())
                cout << "Defeat!\n" << endl;
        }
        if(this->botSunken)
        {
            cout << "You sunken an enemy ship!\n" << endl;
            if(!this->bot.isAlive())
                cout << "Victory!\n";
        }
        this->bot.print2();
    }
    else cout << "error!" << endl;
}

bool Game::areBothAlive()const{return (player.isAlive() && bot.isAlive());}

void Game::write()
{
    ofstream out("save.txt");
    this->player.write(out);
    this->bot.write(out);
    out << this->busyPositions.size();
    for(size_t i = 0; i < this->busyPositions.size(); i++)
        this->busyPositions[i].write(out);
    out << this->both;
    out << this->botv;
    out << this->noError;
    out << this->botSunken;
    out << this->playerSunken;
    out.close();
}

void Game::read()
{
    ifstream in("save.txt");
    if(in.is_open() == false)
        return;
    this->player.read(in);
    this->bot.read(in);
    size_t tmp;
    in >> tmp;
    for(size_t i = 0; i < tmp; i++)
    {
        Position pos;
        pos.read(in);
        this->busyPositions.push_back(pos);
    }
    in >> this->both;
    in >> this->botv;
    in >> this->noError;
    in >> this->botSunken;
    in >> this->playerSunken;
    in.close();
}
