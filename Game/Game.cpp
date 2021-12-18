#include <iostream>
#include <windows.h>
#include "game_func.h"
#include "Weapon.h"
#include <ctime>
#include <stdlib.h>
#include "Player.h"
#include <fstream>
#include "Stranger.h"
#include "Settings.h"
#include "Location.h"
#include "Inventory.h"

using namespace std;



// ______________________________________________MAIN _______________________
int main()
{
    setlocale(LC_ALL, "");

    srand(time(NULL));

    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    int LoadedLvl;
    int LoadedCoins;
    string LoadedNameWeapon;
    float LoadedWeaponDamage;
    float LoadedWeaponCrit;
    int LoadedWeaponCoolDown;
    string LoadedWeaponRare;
    string LoadedLocation;

    int ButtonPressed;
    

    bool isNewGame;

    ShowMenu();
    
    cin >> ButtonPressed;
    
    Settings MYSET;
    string gamename;
    

    while(ButtonPressed < 4)
    {
        if (ButtonPressed == 1)
        {
            //Новая игра
            system("cls");
            isNewGame = true;
            ButtonPressed = 4;
        }
        if (ButtonPressed == 2)
        {
            //Pfuhepbnm buhe
            system("cls");
            isNewGame = false;
            ButtonPressed = 4;
        }
        if (ButtonPressed == 3)
        {
            //Настройки
            ShowSettings(MYSET);
            system("cls");
            ShowMenu();
            cin >> ButtonPressed;
        }
    }
    

    if (!isNewGame) // Загружаем
    {
        LoadedCoins = 100;
        LoadedNameWeapon = "";
        LoadedWeaponDamage = 10.0;
        LoadedWeaponCrit = 5.0;
        LoadedWeaponCoolDown = 1;
        LoadedWeaponRare = "";
        LoadedLocation = "";
    }
    else // Если игра новая
    {
        LoadedLvl = 1;
        LoadedCoins = 0;
        LoadedNameWeapon = "Кулаки";
        LoadedWeaponDamage = 1.0;
        LoadedWeaponCrit = 2.1;
        LoadedWeaponCoolDown = 1;
        LoadedWeaponRare = "обычное";
        LoadedLocation = "полянка";
    }

    Weapon Hands(LoadedNameWeapon, LoadedWeaponDamage, LoadedWeaponCrit, LoadedWeaponCoolDown, LoadedWeaponRare);
    Player P(LoadedLvl, LoadedCoins, Hands, LoadedLocation);

    if (isNewGame)
    {
        P.loc_cave_isopen = false;
        P.loc_desert_isopen = false;
        P.loc_forest_isopen = false;
        P.loc_mountain_isopen = false;
        cout << "Моё имя: \n";
        string my_Name;
        cin >> my_Name;
        P.set_name(my_Name);
        for (int i = 0; i < 10; i++)
        {
            P.Inventory_set_Id_count(i, 0, 0);
        }
    }


    system("cls");
    Stranger Bandit("Бандит Инококентий", 0, 0, "ino.txt");
    Location Field(0, 1, 2, 6, 0, 40, 70, 90, 100, 0, "полянка", "", "", "", "", "");

    GoStory(Bandit, P.get_name(), P, MYSET); // игра начилась стартовый диалог
    system("cls");

    ShowActions(P.get_location());
    int InputForAction = 1;
    while (InputForAction !=0)
    {
        cin >> InputForAction;
        switch (InputForAction)
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
                cout << "Уровень: " << P.get_lvl() << endl;
                cout << "Монет:   " << P.get_coins() << endl;
                ShowInventory(P);
                system("pause");
            }
            break;
        case 2:
            if (P.get_lvl() > 1)
            {
                system("cls");
                printMap(P.get_location(), P);
            }
            break;
        case 3:
            system("cls");
            if (P.get_location() == "полянка") lookUp(Field, P);
            Sleep(1500);
            break;
        case 0:
            ShowMenu(isNewGame);
            cin >> InputForAction;
            if (InputForAction == 2)
            {
                ShowSettings(MYSET);
            }
            break;
        default:
            break;
        }
        system("cls");
        ShowActions(P.get_location());
    }
    system("cls");
    cout << "Перед тем как выйти. Сохраним игру\n 1 - Да\n 2 - нет\n";
    int in;
    cin >> in;
    if (in == 1)
    {
        cout << "слот сохранения: \n";
        cin >> gamename;
    }

    return 0;
}
//__________________________________________END MAIN_________________________
