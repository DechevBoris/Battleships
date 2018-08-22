#include "Player.h"

Player::Player()
{
    Ship* car = new Carrier();
    Ship* bat = new Battleship();
    Ship* cru = new Cruiser();
    Ship* sub = new Submarine();
    Ship* des = new Destroyer();
    this->ships.push_back(car);
    this->ships.push_back(bat);
    this->ships.push_back(cru);
    this->ships.push_back(sub);
    this->ships.push_back(des);

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            this->matrix[i][j] = '.';
    this->shipSunken = false;
}

Player::~Player()
{
    for(size_t i = 0; i < this->ships.size(); i++)
        delete this->ships[i];
}

void Player::positionCarrier(vector<Position> pos)
{
    for(size_t i = 0; i < this->ships.size(); i++)
        if(this->ships[i]->getType().compare("carrier") == 0)
            this->ships[i]->setPosition(pos);
}

void Player::positionBattleship(vector<Position> pos)
{
    for(size_t i = 0; i < this->ships.size(); i++)
        if(this->ships[i]->getType().compare("battleship") == 0)
            this->ships[i]->setPosition(pos);
}

void Player::positionCruiser(vector<Position> pos)
{
    for(size_t i = 0; i < this->ships.size(); i++)
        if(this->ships[i]->getType().compare("cruiser") == 0)
            this->ships[i]->setPosition(pos);
}

void Player::positionSubmarine(vector<Position> pos)
{
    for(size_t i = 0; i < this->ships.size(); i++)
        if(this->ships[i]->getType().compare("submarine") == 0)
            this->ships[i]->setPosition(pos);
}

void Player::positionDestroyer(vector<Position> pos)
{
    for(size_t i = 0; i < this->ships.size(); i++)
        if(this->ships[i]->getType().compare("destroyer") == 0)
            this->ships[i]->setPosition(pos);
}

void Player::getHit(Position pos)
{
    this->shipSunken = false;
    bool flag = false;
    for(size_t i = 0; i < this->ships.size(); i++)
    {
        vector<Position> tmp = this->ships[i]->getPosition();
        for(size_t j = 0; j < tmp.size(); j++)
            if(tmp[j] == pos)
            {
                this->ships[i]->getHit(pos);
                if(!this->ships[i]->isFloating())
                    this->shipSunken = true;
                flag = true;
            }
    }
    if(flag)
        this->matrix[pos.getHorizontal()][pos.getVertical()] = 'X';
    else
        this->matrix[pos.getHorizontal()][pos.getVertical()] = 'O';
}

bool Player::canStrike(string type)const
{
    for(size_t i = 0; i < this->bussyTanks.size(); i++)
        if(this->bussyTanks[i].compare(type) == 0)
            return false;
    return true;
}

vector<Ship*> Player::getShips()const{return this->ships;}

bool Player::isAlive()const
{
    for(size_t i = 0; i < this->ships.size(); i++)
        if(this->ships[i]->isFloating())
            return true;
    return false;
}

void Player::print()const
{
    cout << "      --Your board--" << endl;
    cout << "    0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "    -------------------" << endl;
    for(int i = 0; i <= 9; i++)
        for(int j = 0; j <= 9; j++)
        {
            if(j == 0)
                cout << i << " | ";
            cout << this->matrix[i][j] << " ";
            if(j == 9)
                cout << endl;
        }
}

void Player::print2()const
{
    cout << "                     --Enemy board--" << endl;
    cout << "                   0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "                   -------------------" << endl;
    for(int i = 0; i <= 9; i++)
        for(int j = 0; j <= 9; j++)
        {
            if(j == 0)
            {
                cout << "               ";
                cout << i << " | ";
            }
            cout << this->matrix[i][j] << " ";
            if(j == 9)
                cout << endl;
        }
}

void Player::write(ofstream &out)
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            out << this->matrix[i][j];
    for(size_t i = 0; i < this->ships.size(); i++)
        this->ships[i]->write(out);
    for(size_t i = 0; i < this->bussyTanks.size(); i++)
        out << this->bussyTanks[i];
    out << this->shipSunken;
}

void Player::read(ifstream& in)
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            in >> this->matrix[i][j];
    for(size_t i = 0; i < this->ships.size(); i++)
    {
        if(i == 0)
        {
            Ship* tmp = new Carrier();
            tmp->read(in);
            this->ships.push_back(tmp);
        }
        if(i == 1)
        {
            Ship* tmp = new Battleship();
            tmp->read(in);
            this->ships.push_back(tmp);
        }
        if(i == 2)
        {
            Ship* tmp = new Cruiser();
            tmp->read(in);
            this->ships.push_back(tmp);
        }
        if(i == 3)
        {
            Ship* tmp = new Submarine();
            tmp->read(in);
            this->ships.push_back(tmp);
        }
        if(i == 4)
        {
            Ship* tmp = new Destroyer();
            tmp->read(in);
            this->ships.push_back(tmp);
        }
    }
    for(size_t i =0 ;i < this->bussyTanks.size(); i++)
    {
        string tmp;
        in >> tmp;
        this->bussyTanks.push_back(tmp);
    }
    in >> this->shipSunken;
}

void Player::strike(string type)
{
    this->bussyTanks.push_back(type);
    if(this->bussyTanks.size() == 5)
        this->bussyTanks.clear();
}

bool Player::sunken()const{return this->shipSunken;}
