#include <iostream>

#include "Game.h"

using namespace std;

vector<Position> taken;
vector<Position> takenGeneral;
vector<string> takenShips;

bool busyPosition(Position pos)
{
    for(size_t i = 0; i < taken.size(); i++)
        if(pos == taken[i])
            return true;
    return false;
}

bool busyPositionGeneral(Position pos)
{
    for(size_t i = 0; i < takenGeneral.size(); i++)
        if(pos == takenGeneral[i])
            return true;
    return false;
}

bool validPosition(Position pos)
{
    return (pos.getHorizontal()>= 0 && pos.getHorizontal() < 10 &&
            pos.getVertical() >= 0 && pos.getVertical() < 10);
}

bool coordinatesOk(vector<Position> pos)
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

bool validShipType(string type)
{
    return (type.compare("carrier") == 0 || type.compare("battleship") == 0 || type.compare("cruiser") == 0 ||
            type.compare("submarine") == 0 || type.compare("destroyer") == 0);
}

bool isShipTaken(string type)
{
    for(size_t i = 0; i < takenShips.size(); i++)
        if(takenShips[i].compare(type) == 0)
            return true;
    takenShips.push_back(type);
    if(takenShips.size() == 5)
        takenShips.clear();
    return false;
}

int main()
{
    char start = ' ';
    bool end = false;
    cout << "Welcome to Battleships!" << endl;
    cout << "To see the info, press 'i'.\nTo start, press 's'.To exit the game, press 'e'." << endl;
    while(start != 's')
    {
        cin >> start;
        if(start == 'e')
        {
            system("CLS");
            cout << "Goodbye!";
            end = true;
            break;
        }
        if(start == 'i')
        {
            system("CLS");
            cout << "Description:\nEach player has 5 ships.A carrier, a battleship, a cruiser, a submarine and a destroyer.\n";
            cout << "Each player also has a 10x10 grid.Both players take turns and point at the enemy's grid, where they think\n";
            cout << "a ship could be.A carrier takes 5 squares, the battleship takes 4, the cruiser - 3, submarine - 3 and the destroyer-2.\n";
            cout << "Controls:\nWhen it's your turn, first enter the type of ship you want to use.Valid ships are 'carrier', 'battleship', 'cruiser', \n'submarine'";
            cout << "and 'destroyer'.\nNext you choose the position which you want to attack.Choosing the position happens the following way:\n";
            cout << "First you enter the horizontal coordinates(0-9), next you enter the vertical coordinates(0-9).\n";
            cout << "Wins the one who first destroys all enemy ships.\nGood luck!" << endl;
        }
        if(start != 's' && start != 'i')
        {
            system("CLS");
            cout << "To see the info, press 'i'.\nTo start, press 's'.To exit the game, press 'e'." << endl;
        }
        if(start == 's')
        {
            system("CLS");
            cout << "Let's row!" << endl;
        }
    }
    if(!end)
    {
        Game game;
        cout << "You need to position your ships!\n";
        cout << "The ships must form straight lines on the playing board!\n";
        cout << "Let's start with the carrier!It occupies 5 positions.Enter the horizontal coordinates of the 1st position,\npress enter and do the same with the vertical coordinates of the 1st position!\n";
        int car1stH, car1stV;
        cout << "Horizontal: ";
        cin >> car1stH;
        cout << "\nVertical: ";
        cin >> car1stV;
        Position car1st(car1stH, car1stV);
        if(!validPosition(car1st) || busyPosition(car1st))
            while(!validPosition(car1st) || busyPosition(car1st))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> car1stH;
                cout << "\nVertical: ";
                cin >> car1stV;
                car1st.setHorizontal(car1stH);
                car1st.setVertical(car1stV);
            }
        taken.push_back(car1st);
        system("CLS");
        cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
        int car2ndH, car2ndV;
        cout << "Horizontal: ";
        cin >> car2ndH;
        cout << "\nVertical: ";
        cin >> car2ndV;
        Position car2nd(car2ndH, car2ndV);
        if(!validPosition(car2nd) || busyPosition(car2nd))
            while(!validPosition(car2nd) || busyPosition(car2nd))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";
                cout << "Horizontal: ";
                cin >> car2ndH;
                cout << "\nVertical: ";
                cin >> car2ndV;
                car2nd.setHorizontal(car2ndH);
                car2nd.setVertical(car2ndV);
            }
        taken.push_back(car2nd);
        system("CLS");
        cout << "Now let's do the same with the 3rd positon.Choose the horizontal and the vertical coordinates!\n";
        int car3rdH, car3rdV;
        cout << "Horizontal: ";
        cin >> car3rdH;
        cout << "\nVertical: ";
        cin >> car3rdV;
        Position car3rd(car3rdH, car3rdV);
        if(!validPosition(car3rd) || busyPosition(car3rd))
            while(!validPosition(car3rd) || busyPosition(car3rd))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 3rd position, press enter and do the same with the vertical coordinates of the 3rd position!\n";
                cout << "Horizontal: ";
                cin >> car3rdH;
                cout << "\nVertical: ";
                cin >> car3rdV;
                car3rd.setHorizontal(car3rdH);
                car3rd.setVertical(car3rdV);
            }
        taken.push_back(car3rd);
        system("CLS");
        cout << "Now let's do the same with the 4th positon.Choose the horizontal and the vertical coordinates!\n";
        int car4thH, car4thV;
        cout << "Horizontal: ";
        cin >> car4thH;
        cout << "\nVertical: ";
        cin >> car4thV;
        Position car4th(car4thH, car4thV);
        if(!validPosition(car4th) || busyPosition(car4th))
            while(!validPosition(car4th) || busyPosition(car4th))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 4th position, press enter and do the same with the vertical coordinates of the 4th position!\n";
                cout << "Horizontal: ";
                cin >> car4thH;
                cout << "\nVertical: ";
                cin >> car4thV;
                car4th.setHorizontal(car4thH);
                car4th.setVertical(car4thV);
            }
        taken.push_back(car4th);
        system("CLS");
        cout << "Now let's do the same with the 5th positon.Choose the horizontal and the vertical coordinates!\n";
        int car5thH, car5thV;
        cout << "Horizontal: ";
        cin >> car5thH;
        cout << "\nVertical: ";
        cin >> car5thV;
        Position car5th(car5thH, car5thV);
        if(!validPosition(car5th) || busyPosition(car5th))
            while(!validPosition(car5th) || busyPosition(car5th))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 5th position, press enter and do the same with the vertical coordinates of the 5th position!\n";
                cout << "Horizontal: ";
                cin >> car5thH;
                cout << "\nVertical: ";
                cin >> car5thV;
                car5th.setHorizontal(car5thH);
                car5th.setVertical(car5thV);
            }
        taken.push_back(car5th);
        vector<Position> car;
        car.push_back(car1st);
        car.push_back(car2nd);
        car.push_back(car3rd);
        car.push_back(car4th);
        car.push_back(car5th);
        if(!coordinatesOk(car))
            while(!coordinatesOk(car))
            {
                taken.clear();
                system("CLS");
                cout << "The positions of your carrier don't form a straight line!Try positioning your carrier again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> car1stH;
                cout << "\nVertical: ";
                cin >> car1stV;
                car1st.setHorizontal(car1stH);
                car1st.setVertical(car1stV);
                if(!validPosition(car1st) || busyPosition(car1st))
                    while(!validPosition(car1st) || busyPosition(car1st))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                        cout << "Horizontal: ";
                        cin >> car1stH;
                        cout << "\nVertical: ";
                        cin >> car1stV;
                        car1st.setHorizontal(car1stH);
                        car1st.setVertical(car1stV);
                    }
                taken.push_back(car1st);
                system("CLS");
                cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> car2ndH;
                cout << "\nVertical: ";
                cin >> car2ndV;
                car2nd.setHorizontal(car2ndH);
                car2nd.setVertical(car2ndV);
                if(!validPosition(car2nd) || busyPosition(car2nd))
                    while(!validPosition(car2nd) || busyPosition(car2nd))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";
                        cout << "Horizontal: ";
                        cin >> car2ndH;
                        cout << "\nVertical: ";
                        cin >> car2ndV;
                        car2nd.setHorizontal(car2ndH);
                        car2nd.setVertical(car2ndV);
                    }
                taken.push_back(car2nd);
                system("CLS");
                cout << "Now let's do the same with the 3rd positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> car3rdH;
                cout << "\nVertical: ";
                cin >> car3rdV;
                car3rd.setHorizontal(car3rdH);
                car3rd.setVertical(car3rdV);
                if(!validPosition(car3rd) || busyPosition(car3rd))
                    while(!validPosition(car3rd) || busyPosition(car3rd))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 3rd position, press enter and do the same with the vertical coordinates of the 3rd position!\n";
                        cout << "Horizontal: ";
                        cin >> car3rdH;
                        cout << "\nVertical: ";
                        cin >> car3rdV;
                        car3rd.setHorizontal(car3rdH);
                        car3rd.setVertical(car3rdV);
                    }
                taken.push_back(car3rd);
                system("CLS");
                cout << "Now let's do the same with the 4th positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> car4thH;
                cout << "\nVertical: ";
                cin >> car4thV;
                car4th.setHorizontal(car4thH);
                car4th.setVertical(car4thV);
                if(!validPosition(car4th) || busyPosition(car4th))
                    while(!validPosition(car4th) || busyPosition(car4th))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 4th position, press enter and do the same with the vertical coordinates of the 4th position!\n";
                        cout << "Horizontal: ";
                        cin >> car4thH;
                        cout << "\nVertical: ";
                        cin >> car4thV;
                        car4th.setHorizontal(car4thH);
                        car4th.setVertical(car4thV);
                    }
                taken.push_back(car4th);
                system("CLS");
                cout << "Now let's do the same with the 5th positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> car5thH;
                cout << "\nVertical: ";
                cin >> car5thV;
                car5th.setHorizontal(car5thH);
                car5th.setVertical(car5thV);
                if(!validPosition(car5th) || busyPosition(car5th))
                    while(!validPosition(car5th) || busyPosition(car5th))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 5th position, press enter and do the same with the vertical coordinates of the 5th position!\n";
                        cout << "Horizontal: ";
                        cin >> car5thH;
                        cout << "\nVertical: ";
                        cin >> car5thV;
                        car5th.setHorizontal(car5thH);
                        car5th.setVertical(car5thV);
                    }
                taken.push_back(car5th);
                car.clear();
                car.push_back(car1st);
                car.push_back(car2nd);
                car.push_back(car3rd);
                car.push_back(car4th);
                car.push_back(car5th);
            }
        taken.clear();
        takenGeneral.push_back(car1st);
        takenGeneral.push_back(car2nd);
        takenGeneral.push_back(car3rd);
        takenGeneral.push_back(car4th);
        takenGeneral.push_back(car5th);


        system("CLS");
        cout << "You successfully positioned your carrier!Now do the same with the battleship!It takes 4 positions.\n";
        cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
        int bat1stH, bat1stV;
        cout << "Horizontal: ";
        cin >> bat1stH;
        cout << "\nVertical: ";
        cin >> bat1stV;
        Position bat1st(bat1stH, bat1stV);
        if(!validPosition(bat1st) || busyPosition(bat1st) || busyPositionGeneral(bat1st))
            while(!validPosition(bat1st) || busyPosition(bat1st) || busyPositionGeneral(bat1st))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> bat1stH;
                cout << "\nVertical: ";
                cin >> bat1stV;
                bat1st.setHorizontal(bat1stH);
                bat1st.setVertical(bat1stV);
            }
        taken.push_back(bat1st);
        system("CLS");
        cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
        int bat2ndH, bat2ndV;
        cout << "Horizontal: ";
        cin >> bat2ndH;
        cout << "\nVertical: ";
        cin >> bat2ndV;
        Position bat2nd(bat2ndH, bat2ndV);
        if(!validPosition(bat2nd) || busyPosition(bat2nd) || busyPositionGeneral(bat2nd))
            while(!validPosition(bat2nd) || busyPosition(bat2nd) || busyPositionGeneral(bat2nd))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";
                cout << "Horizontal: ";
                cin >> bat2ndH;
                cout << "\nVertical: ";
                cin >> bat2ndV;
                bat2nd.setHorizontal(bat2ndH);
                bat2nd.setVertical(bat2ndV);
            }
        taken.push_back(bat2nd);
        system("CLS");
        cout << "Now let's do the same with the 3rd positon.Choose the horizontal and the vertical coordinates!\n";
        int bat3rdH, bat3rdV;
        cout << "Horizontal: ";
        cin >> bat3rdH;
        cout << "\nVertical: ";
        cin >> bat3rdV;
        Position bat3rd(bat3rdH, bat3rdV);
        if(!validPosition(bat3rd) || busyPosition(bat3rd) || busyPositionGeneral(bat3rd))
            while(!validPosition(bat3rd) || busyPosition(bat3rd) || busyPositionGeneral(bat3rd))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 3rd position, press enter and do the same with the vertical coordinates of the 3rd position!\n";
                cout << "Horizontal: ";
                cin >> bat3rdH;
                cout << "\nVertical: ";
                cin >> bat3rdV;
                bat3rd.setHorizontal(bat3rdH);
                bat3rd.setVertical(bat3rdV);
            }
        taken.push_back(bat3rd);
        system("CLS");
        cout << "Now let's do the same with the 4th positon.Choose the horizontal and the vertical coordinates!\n";
        int bat4thH, bat4thV;
        cout << "Horizontal: ";
        cin >> bat4thH;
        cout << "\nVertical: ";
        cin >> bat4thV;
        Position bat4th(bat4thH, bat4thV);
        if(!validPosition(bat4th) || busyPosition(bat4th) || busyPositionGeneral(bat4th))
            while(!validPosition(bat4th) || busyPosition(bat4th) || busyPositionGeneral(bat4th))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 4th position, press enter and do the same with the vertical coordinates of the 4th position!\n";
                cout << "Horizontal: ";
                cin >> bat4thH;
                cout << "\nVertical: ";
                cin >> bat4thV;
                bat4th.setHorizontal(bat4thH);
                bat4th.setVertical(bat4thV);
            }
        taken.push_back(bat4th);
        vector<Position> bat;
        bat.push_back(bat1st);
        bat.push_back(bat2nd);
        bat.push_back(bat3rd);
        bat.push_back(bat4th);
        if(!coordinatesOk(bat))
            while(!coordinatesOk(bat))
            {
                taken.clear();
                system("CLS");
                cout << "The positions of your battleship don't form a straight line!Try positioning your battleship again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> bat1stH;
                cout << "\nVertical: ";
                cin >> bat1stV;
                bat1st.setHorizontal(bat1stH);
                bat1st.setVertical(bat1stV);
                if(!validPosition(bat1st) || busyPosition(bat1st) || busyPositionGeneral(bat1st))
                    while(!validPosition(bat1st) || busyPosition(bat1st) || busyPositionGeneral(bat1st))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                        cout << "Horizontal: ";
                        cin >> bat1stH;
                        cout << "\nVertical: ";
                        cin >> bat1stV;
                        bat1st.setHorizontal(bat1stH);
                        bat1st.setVertical(bat1stV);
                    }
                taken.push_back(bat1st);
                system("CLS");
                cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> bat2ndH;
                cout << "\nVertical: ";
                cin >> bat2ndV;
                bat2nd.setHorizontal(bat2ndH);
                bat2nd.setVertical(bat2ndV);
                if(!validPosition(bat2nd) || busyPosition(bat2nd) || busyPositionGeneral(bat2nd))
                    while(!validPosition(bat2nd) || busyPosition(bat2nd) || busyPositionGeneral(bat2nd))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";
                        cout << "Horizontal: ";
                        cin >> bat2ndH;
                        cout << "\nVertical: ";
                        cin >> bat2ndV;
                        bat2nd.setHorizontal(bat2ndH);
                        bat2nd.setVertical(bat2ndV);
                    }
                taken.push_back(bat2nd);
                system("CLS");
                cout << "Now let's do the same with the 3rd positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> bat3rdH;
                cout << "\nVertical: ";
                cin >> bat3rdV;
                bat3rd.setHorizontal(bat3rdH);
                bat3rd.setVertical(bat3rdV);
                if(!validPosition(bat3rd) || busyPosition(bat3rd) || busyPositionGeneral(bat3rd))
                    while(!validPosition(bat3rd) || busyPosition(bat3rd) || busyPositionGeneral(bat3rd))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 3rd position, press enter and do the same with the vertical coordinates of the 3rd position!\n";
                        cout << "Horizontal: ";
                        cin >> bat3rdH;
                        cout << "\nVertical: ";
                        cin >> bat3rdV;
                        bat3rd.setHorizontal(bat3rdH);
                        bat3rd.setVertical(bat3rdV);
                    }
                taken.push_back(bat3rd);
                system("CLS");
                cout << "Now let's do the same with the 4th positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> bat4thH;
                cout << "\nVertical: ";
                cin >> bat4thV;
                bat4th.setHorizontal(bat4thH);
                bat4th.setVertical(bat4thV);
                if(!validPosition(bat4th) || busyPosition(bat4th) || busyPositionGeneral(bat4th))
                    while(!validPosition(bat4th) || busyPosition(bat4th) || busyPositionGeneral(bat4th))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 4th position, press enter and do the same with the vertical coordinates of the 4th position!\n";
                        cout << "Horizontal: ";
                        cin >> bat4thH;
                        cout << "\nVertical: ";
                        cin >> bat4thV;
                        bat4th.setHorizontal(bat4thH);
                        bat4th.setVertical(bat4thV);
                    }
                taken.push_back(bat4th);
                bat.clear();
                bat.push_back(bat1st);
                bat.push_back(bat2nd);
                bat.push_back(bat3rd);
                bat.push_back(bat4th);
            }
        taken.clear();
        takenGeneral.push_back(bat1st);
        takenGeneral.push_back(bat2nd);
        takenGeneral.push_back(bat3rd);
        takenGeneral.push_back(bat4th);


        system("CLS");
        cout << "You successfully positioned your battleship!Now do the same with the cruiser!It takes 3 positions.\n";
        cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
        int cru1stH, cru1stV;
        cout << "Horizontal: ";
        cin >> cru1stH;
        cout << "\nVertical: ";
        cin >> cru1stV;
        Position cru1st(cru1stH, cru1stV);
        if(!validPosition(cru1st) || busyPosition(cru1st) || busyPositionGeneral(cru1st))
            while(!validPosition(cru1st) || busyPosition(cru1st) || busyPositionGeneral(cru1st))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> cru1stH;
                cout << "\nVertical: ";
                cin >> cru1stV;
                cru1st.setHorizontal(cru1stH);
                cru1st.setVertical(cru1stV);
            }
        taken.push_back(cru1st);
        system("CLS");
        cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
        int cru2ndH, cru2ndV;
        cout << "Horizontal: ";
        cin >> cru2ndH;
        cout << "\nVertical: ";
        cin >> cru2ndV;
        Position cru2nd(cru2ndH, cru2ndV);
        if(!validPosition(cru2nd) || busyPosition(cru2nd) || busyPositionGeneral(cru2nd))
            while(!validPosition(cru2nd) || busyPosition(cru2nd) || busyPositionGeneral(cru2nd))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";
                cout << "Horizontal: ";
                cin >> cru2ndH;
                cout << "\nVertical: ";
                cin >> cru2ndV;
                cru2nd.setHorizontal(cru2ndH);
                cru2nd.setVertical(cru2ndV);
            }
        taken.push_back(cru2nd);
        system("CLS");
        cout << "Now let's do the same with the 3rd positon.Choose the horizontal and the vertical coordinates!\n";
        int cru3rdH, cru3rdV;
        cout << "Horizontal: ";
        cin >> cru3rdH;
        cout << "\nVertical: ";
        cin >> cru3rdV;
        Position cru3rd(cru3rdH, cru3rdV);
        if(!validPosition(cru3rd) || busyPosition(cru3rd) || busyPositionGeneral(cru3rd))
            while(!validPosition(cru3rd) || busyPosition(cru3rd) || busyPositionGeneral(cru3rd))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 3rd position, press enter and do the same with the vertical coordinates of the 3rd position!\n";
                cout << "Horizontal: ";
                cin >> cru3rdH;
                cout << "\nVertical: ";
                cin >> cru3rdV;
                cru3rd.setHorizontal(cru3rdH);
                cru3rd.setVertical(cru3rdV);
            }
        taken.push_back(cru3rd);
        vector<Position> cru;
        cru.push_back(cru1st);
        cru.push_back(cru2nd);
        cru.push_back(cru3rd);
        if(!coordinatesOk(cru))
            while(!coordinatesOk(cru))
            {
                taken.clear();
                system("CLS");
                cout << "The positions of your cruiser don't form a straight line!Try positioning your cruiser again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> cru1stH;
                cout << "\nVertical: ";
                cin >> cru1stV;
                cru1st.setHorizontal(cru1stH);
                cru1st.setVertical(cru1stV);
                if(!validPosition(cru1st) || busyPosition(cru1st) || busyPositionGeneral(cru1st))
                    while(!validPosition(cru1st) || busyPosition(cru1st) || busyPositionGeneral(cru1st))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                        cout << "Horizontal: ";
                        cin >> cru1stH;
                        cout << "\nVertical: ";
                        cin >> cru1stV;
                        cru1st.setHorizontal(cru1stH);
                        cru1st.setVertical(cru1stV);
                    }
                taken.push_back(cru1st);
                system("CLS");
                cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> cru2ndH;
                cout << "\nVertical: ";
                cin >> cru2ndV;
                cru2nd.setHorizontal(cru2ndH);
                cru2nd.setVertical(cru2ndV);
                if(!validPosition(cru2nd) || busyPosition(cru2nd) || busyPositionGeneral(cru2nd))
                    while(!validPosition(cru2nd) || busyPosition(cru2nd) || busyPositionGeneral(cru2nd))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";\
                        cout << "Horizontal: ";
                        cin >> cru2ndH;
                        cout << "\nVertical: ";
                        cin >> cru2ndV;
                        cru2nd.setHorizontal(cru2ndH);
                        cru2nd.setVertical(cru2ndV);
                    }
                taken.push_back(cru2nd);
                system("CLS");
                cout << "Now let's do the same with the 3rd positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> cru3rdH;
                cout << "\nVertical: ";
                cin >> cru3rdV;
                cru3rd.setHorizontal(cru3rdH);
                cru3rd.setVertical(cru3rdV);
                if(!validPosition(cru3rd) || busyPosition(cru3rd) || busyPositionGeneral(cru3rd))
                    while(!validPosition(cru3rd) || busyPosition(cru3rd) || busyPositionGeneral(cru3rd))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 3rd position, press enter and do the same with the vertical coordinates of the 3rd position!\n";
                        cout << "Horizontal: ";
                        cin >> cru3rdH;
                        cout << "\nVertical: ";
                        cin >> cru3rdV;
                        cru3rd.setHorizontal(cru3rdH);
                        cru3rd.setVertical(cru3rdV);
                    }
                taken.push_back(cru3rd);
                cru.clear();
                cru.push_back(cru1st);
                cru.push_back(cru2nd);
                cru.push_back(cru3rd);
            }
        taken.clear();
        takenGeneral.push_back(cru1st);
        takenGeneral.push_back(cru2nd);
        takenGeneral.push_back(cru3rd);


        system("CLS");
        cout << "You successfully positioned your cruiser!Now do the same with the submarine!It takes 3 positions.\n";
        cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
        int sub1stH, sub1stV;
        cout << "Horizontal: ";
        cin >> sub1stH;
        cout << "\nVertical: ";
        cin >> sub1stV;
        Position sub1st(sub1stH, sub1stV);
        if(!validPosition(sub1st) || busyPosition(sub1st) || busyPositionGeneral(sub1st))
            while(!validPosition(sub1st) || busyPosition(sub1st) || busyPositionGeneral(sub1st))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> sub1stH;
                cout << "\nVertical: ";
                cin >> sub1stV;
                sub1st.setHorizontal(sub1stH);
                sub1st.setVertical(sub1stV);
            }
        taken.push_back(sub1st);
        system("CLS");
        cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
        int sub2ndH, sub2ndV;
        cout << "Horizontal: ";
        cin >> sub2ndH;
        cout << "\nVertical: ";
        cin >> sub2ndV;
        Position sub2nd(sub2ndH, sub2ndV);
        if(!validPosition(sub2nd) || busyPosition(sub2nd) || busyPositionGeneral(sub2nd))
            while(!validPosition(sub2nd) || busyPosition(sub2nd) || busyPositionGeneral(sub2nd))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";
                cout << "Horizontal: ";
                cin >> sub2ndH;
                cout << "\nVertical: ";
                cin >> sub2ndV;
                sub2nd.setHorizontal(sub2ndH);
                sub2nd.setVertical(sub2ndV);
            }
        taken.push_back(sub2nd);
        system("CLS");
        cout << "Now let's do the same with the 3rd positon.Choose the horizontal and the vertical coordinates!\n";
        int sub3rdH, sub3rdV;
        cout << "Horizontal: ";
        cin >> sub3rdH;
        cout << "\nVertical: ";
        cin >> sub3rdV;
        Position sub3rd(sub3rdH, sub3rdV);
        if(!validPosition(sub3rd) || busyPosition(sub3rd) || busyPositionGeneral(sub3rd))
            while(!validPosition(sub3rd) || busyPosition(sub3rd) || busyPositionGeneral(sub3rd))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 3rd position, press enter and do the same with the vertical coordinates of the 3rd position!\n";
                cout << "Horizontal: ";
                cin >> sub3rdH;
                cout << "\nVertical: ";
                cin >> sub3rdV;
                sub3rd.setHorizontal(sub3rdH);
                sub3rd.setVertical(sub3rdV);
            }
        taken.push_back(sub3rd);
        vector<Position> sub;
        sub.push_back(sub1st);
        sub.push_back(sub2nd);
        sub.push_back(sub3rd);
        if(!coordinatesOk(sub))
            while(!coordinatesOk(sub))
            {
                taken.clear();
                system("CLS");
                cout << "The positions of your submarine don't form a straight line!Try positioning your submarine again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> sub1stH;
                cout << "\nVertical: ";
                cin >> sub1stV;
                sub1st.setHorizontal(sub1stH);
                sub1st.setVertical(sub1stV);
                if(!validPosition(sub1st) || busyPosition(sub1st) || busyPositionGeneral(sub1st))
                    while(!validPosition(sub1st) || busyPosition(sub1st) || busyPositionGeneral(sub1st))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                        cout << "Horizontal: ";
                        cin >> sub1stH;
                        cout << "\nVertical: ";
                        cin >> sub1stV;
                        sub1st.setHorizontal(sub1stH);
                        sub1st.setVertical(sub1stV);
                    }
                taken.push_back(sub1st);
                system("CLS");
                cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> sub2ndH;
                cout << "\nVertical: ";
                cin >> sub2ndV;
                sub2nd.setHorizontal(sub2ndH);
                sub2nd.setVertical(sub2ndV);
                if(!validPosition(sub2nd) || busyPosition(sub2nd) || busyPositionGeneral(sub2nd))
                    while(!validPosition(sub2nd) || busyPosition(sub2nd) || busyPositionGeneral(sub2nd))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";
                        cout << "Horizontal: ";
                        cin >> sub2ndH;
                        cout << "\nVertical: ";
                        cin >> sub2ndV;
                        sub2nd.setHorizontal(sub2ndH);
                        sub2nd.setVertical(sub2ndV);
                    }
                taken.push_back(sub2nd);
                system("CLS");
                cout << "Now let's do the same with the 3rd positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> sub3rdH;
                cout << "\nVertical: ";
                cin >> sub3rdV;
                sub3rd.setHorizontal(sub3rdH);
                sub3rd.setVertical(sub3rdV);
                if(!validPosition(sub3rd) || busyPosition(sub3rd) || busyPositionGeneral(sub3rd))
                    while(!validPosition(sub3rd) || busyPosition(sub3rd) || busyPositionGeneral(sub3rd))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 3rd position, press enter and do the same with the vertical coordinates of the 3rd position!\n";
                        cout << "Horizontal: ";
                        cin >> sub3rdH;
                        cout << "\nVertical: ";
                        cin >> sub3rdV;
                        sub3rd.setHorizontal(sub3rdH);
                        sub3rd.setVertical(sub3rdV);
                    }
                taken.push_back(sub3rd);
                sub.clear();
                sub.push_back(sub1st);
                sub.push_back(sub2nd);
                sub.push_back(sub3rd);
            }
        taken.clear();
        takenGeneral.push_back(sub1st);
        takenGeneral.push_back(sub2nd);
        takenGeneral.push_back(sub3rd);


        system("CLS");
        cout << "You successfully positioned your submarine!Now do the same with the destroyer!It takes 2 positions.\n";
        cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
        int des1stH, des1stV;
        cout << "Horizontal: ";
        cin >> des1stH;
        cout << "\nVertical: ";
        cin >> des1stV;
        Position des1st(des1stH, des1stV);
        if(!validPosition(des1st) || busyPosition(des1st) || busyPositionGeneral(des1st))
            while(!validPosition(des1st) || busyPosition(des1st) || busyPositionGeneral(des1st))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> des1stH;
                cout << "\nVertical: ";
                cin >> des1stV;
                des1st.setHorizontal(des1stH);
                des1st.setVertical(des1stV);
            }
        taken.push_back(des1st);
        system("CLS");
        cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
        int des2ndH, des2ndV;
        cout << "Horizontal: ";
        cin >> des2ndH;
        cout << "\nVertical: ";
        cin >> des2ndV;
        Position des2nd(des2ndH, des2ndV);
        if(!validPosition(des2nd) || busyPosition(des2nd) || busyPositionGeneral(des2nd))
            while(!validPosition(des2nd) || busyPosition(des2nd) || busyPositionGeneral(des2nd))
            {
                system("CLS");
                cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";
                cout << "Horizontal: ";
                cin >> des2ndH;
                cout << "\nVertical: ";
                cin >> des2ndV;
                des2nd.setHorizontal(des2ndH);
                des2nd.setVertical(des2ndV);
            }
        taken.push_back(des2nd);
        vector<Position> des;
        des.push_back(des1st);
        des.push_back(des2nd);
        if(!coordinatesOk(des))
            while(!coordinatesOk(des))
            {
                taken.clear();
                system("CLS");
                cout << "The positions of your destroyer don't form a straight line!Try positioning your destroyer again!\n";
                cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                cout << "Horizontal: ";
                cin >> des1stH;
                cout << "\nVertical: ";
                cin >> des1stV;
                des1st.setHorizontal(des1stH);
                des1st.setVertical(des1stV);
                if(!validPosition(des1st) || busyPosition(des1st) || busyPositionGeneral(des1st))
                    while(!validPosition(des1st) || busyPosition(des1st) || busyPositionGeneral(des1st))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 1st position, press enter and do the same with the vertical coordinates of the 1st position!\n";
                        cout << "Horizontal: ";
                        cin >> des1stH;
                        cout << "\nVertical: ";
                        cin >> des1stV;
                        des1st.setHorizontal(des1stH);
                        des1st.setVertical(des1stV);
                    }
                taken.push_back(des1st);
                system("CLS");
                cout << "Now let's do the same with the 2nd positon.Choose the horizontal and the vertical coordinates!\n";
                cout << "Horizontal: ";
                cin >> des2ndH;
                cout << "\nVertical: ";
                cin >> des2ndV;
                des2nd.setHorizontal(des2ndH);
                des2nd.setVertical(des2ndV);
                if(!validPosition(des2nd) || busyPosition(des2nd) || busyPositionGeneral(des2nd))
                    while(!validPosition(des2nd) || busyPosition(des2nd) || busyPositionGeneral(des2nd))
                    {
                        system("CLS");
                        cout << "Yor either entered invalid coordinates or the current position is busy!Try again!\n";
                        cout << "Enter the horizontal coordinates of the 2nd position, press enter and do the same with the vertical coordinates of the 2nd position!\n";
                        cout << "Horizontal: ";
                        cin >> des2ndH;
                        cout << "\nVertical: ";
                        cin >> des2ndV;
                        des2nd.setHorizontal(des2ndH);
                        des2nd.setVertical(des2ndV);
                    }
                taken.push_back(des2nd);
                des.clear();
                des.push_back(des1st);
                des.push_back(des2nd);
            }
        taken.clear();
        takenGeneral.push_back(des1st);
        takenGeneral.push_back(des2nd);
        system("CLS");
        cout << "You positioned your ships successfully!Let the battle beggin!\n";
        game.playerPositioning(car,bat,cru,sub,des);
        game.botPositioning();
        game.print();
        cout << "Choose the type of ship you want to use and the position you want to attack.\n";
        cout << "(First the horizontal and then the vertical coordinates)\n";
        cout << "Note:When you fire with one ship, you must fire with all other 4 ships before firing with the same one again!\n";
        cout << "To continue, press 'c'!\nTo exit the game, press 'e'\n";
        char n = ' ';
        cin >> n;
        while(n != 'c')
        {
            if(n == 'e')
                exit(-1);
            system("CLS");
            cout << "To continue, press 'c'!\nTo exit the game, press 'e'\n";
            cin >> n;
        }
        while(game.areBothAlive())
        {
            system("CLS");
            cout << "Ship type: ";
            string shipType;
            cin >> shipType;
            while(!validShipType(shipType) || isShipTaken(shipType))
            {
                system("CLS");
                cout << "You either chose invalid ship type or you already used this ship in the current round!\n";
                cout << "Choose another ship type!\n";
                cout << "Ship type: ";
                cin >> shipType;
            }
            system("CLS");
            cout << "Postition's horizontal coordinates: ";
            int hor;
            cin >> hor;
            cout << "\nPostition's vertical coordinates: ";
            int ver;
            cin >> ver;
            Position attackPos(hor,ver);
            while(!validPosition(attackPos))
            {
                system("CLS");
                cout << "The position you want to attack is invalid!Try again!\n";
                cout << "Postition's horizontal coordinates: ";
                cin >> hor;
                cout << "\nPostition's vertical coordinates: ";
                cin >> ver;
                attackPos.setHorizontal(hor);
                attackPos.setVertical(ver);
            }
            system("CLS");
            game.playerTurn(shipType, attackPos);
            game.print();
            cout << "To continue 'c'\n";
            char q = ' ';
            cin >> q;
            while(q != 'c')
            {
                cout << "To continue 'c'\n";
                cin >> q;
            }
            system("CLS");
            game.botTurn();
            game.print();
            cout << "To proceed the nex round press 'p'\n";
            char p = ' ';
            cin >> p;
            while(p != 'p')
            {
                cout << "To proceed the nex round press 'p'\n";
                cin >> p;
            }
        }
        game.write();
    }

//    Position p1(1,2);
//    Position p2(1,3);
//    Position p3(1,4);
//    Position p4(1,5);
//    Position p5(1,6);
//    vector<Position> car;
//    car.push_back(p1);
//    car.push_back(p2);
//    car.push_back(p3);
//    car.push_back(p4);
//    car.push_back(p5);
//
//    Position p6(0,9);
//    Position p7(1,9);
//    Position p8(2,9);
//    Position p9(3,9);
//    vector<Position> bat;
//    bat.push_back(p6);
//    bat.push_back(p7);
//    bat.push_back(p8);
//    bat.push_back(p9);
//
//    Position p10(2,0);
//    Position p11(3,0);
//    Position p12(4,0);
//    vector<Position> cru;
//    cru.push_back(p10);
//    cru.push_back(p11);
//    cru.push_back(p12);
//
//    Position p13(9,0);
//    Position p14(9,1);
//    Position p15(9,2);
//    vector<Position> sub;
//    sub.push_back(p13);
//    sub.push_back(p14);
//    sub.push_back(p15);
//
//    Position p16(0,1);
//    Position p17(0,2);
//    //Position p17(9,11); //Invalid position for test
//    vector<Position> des;
//    des.push_back(p16);
//    des.push_back(p17);
//
//    Game game;
//    game.playerPositioning(car,bat,cru,sub,des);
//    game.botPositioning();
//    game.print();

//    system("CLS");
//    Position ap1(0,0);
//    game.playerTurn("carrier", ap1);
//    game.print();
//    system("CLS");
//    game.botTurn();
//    game.print();
//    system("CLS");
//    Position ap2(0,1);
//    game.playerTurn("battleship", ap2);
//    game.print();
//    system("CLS");
//    game.botTurn();
//    game.print();
//    system("CLS");
//    Position ap3(0,2);
//    game.playerTurn("cruiser", ap3);
//    game.print();
//    system("CLS");
//    game.botTurn();
//    game.print();
//    system("CLS");
//    Position ap4(0,3);
//    game.playerTurn("submarine", ap4);
//    game.print();
//    system("CLS");
//    game.botTurn();
//    game.print();
//    system("CLS");
//    Position ap5(0,4);
//    game.playerTurn("destroyer", ap5);
//    game.print();
//    system("CLS");
//    game.botTurn();
//    game.print();



    return 0;
}
