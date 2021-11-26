#include <iostream>
#include <windows.h>
#include "game_func.h"
#include "Weapon.h"
#include <ctime>
#include <stdlib.h>
#include "Player.h"
#include <fstream>

using namespace std;
int SetRundomColorOfRare(); // Прототип функции

const int CL_BLACK_WHITE = 15;
const int CL_BLACK_RED = 12;
const int CL_YELLOW_BLACK = 96;
const int CL_GREEN_WHITE = 39;

const int CL_BLACK_BLU = 1;
const int CL_BLACK_GREY = 8;
const int CL_BLACK_GREEN = 2;
const int CL_BLACK_PURP = 5;
const int CL_BLACK_YELLOW = 6;
// ______________________________________________MAIN _______________________
int main()
{

    setlocale(LC_ALL, "Russian");

    srand(time(NULL));

    ShowMenu();
    int input;
    cin >> input;
    while (input<0 && input > 3)
    {
        cout << "Ввведи адекватное число\n";
        system("cls");
        ShowMenu();
        cin >> input;
    }

    string gamename;
    bool isNewGame;

    while (input != 3)
    {
        switch (input)
        {
        case 1:
            system("cls");
            cout << " введите Имя новой игры. В двльнейшем при входе нужно будет его заного указть\n";
            cin >> gamename;
            gamename += ".txt";
            isNewGame = true;
            input = 3;
            break;
        case 2:
            system("cls");
            cout << " введите сохраненной игры\n";
            cin >> gamename;
            gamename += ".txt";
            isNewGame = false;
            input = 3;
            break;
        default:
            gamename = "";
            break;
        }
    }

    /*
   ПЕременные которые получим из файла или 0 для новой игры
    */
    int curlvl;
    int curcoin;
    string nameofweapon;
    int weapondamage;
    int weaponcrit;
    int critchanse;
    string curtype;
    string currare;

    if (!isNewGame) // Если есть ужесохранение
    {
        ifstream in;
        in.open(gamename);
        in >> curlvl;
        in.close();
        curcoin = 100;
        nameofweapon = "Что-то";
        weapondamage = 10.0;
        weaponcrit = 1.5;
        critchanse = 25.0;
        curtype = "тип";
        currare = "редкость";
    }
    else // Если игра новая
    {
        curlvl = 1;
        curcoin = 0;
        nameofweapon = "Кулаки";
        weapondamage = 1.0;
        weaponcrit = 1.5;
        critchanse = 25.0;
        curtype = "булава";
        currare = "обычное";
    }
    Weapon Hands(nameofweapon, weapondamage, weaponcrit, critchanse, curtype, currare);
    Player P(curlvl, curcoin, Hands);

    
    if(isNewGame)
    {
        cout << "Введите свое имя !!! на английском !!! а то будеьш без имени сидеть\n";
        string my_Name;
        cin >> my_Name;
        P.set_name(my_Name);
    }
    system("cls");
    cout << " твое имя " << P.get_name() << endl;
    ShowActions(P.get_lvl());
    int c;
    cin >> c;
    while (c!=5)
    {
        switch (c)
        {
        case 1:
            if (P.get_lvl() > 1)
            {
                system("cls");
                cout << "  0   \t" << P.get_name() << endl;
                cout << " /|?   \n";
                cout << "  ^    \n";
                cout << " / |  \n";
                DescribeWeapon(P.get_weapon());
                cout << "Твой уровень " << P.get_lvl() << endl;
                system("pause");
            }
            break;
        case 2:
            if (P.get_lvl() > 2)
            {

            }
            break;
        case 3:
            if (P.get_lvl() > 1)
            {

            }
            break;
        case 4:
            system("cls");
            GoStory(P.get_lvl(),P.get_name(),P);
            break;
        default:
            break;
        }
        system("cls");
        ShowActions(P.get_lvl());
        cin >> c;
    }

    return 0;
}
//__________________________________________END MAIN_________________________
