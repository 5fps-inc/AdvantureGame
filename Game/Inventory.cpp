#include <iostream>
#include "Inventory.h"

using namespace std;

void ShowInventory(Player& P)
{
    cout << "\t ��������� \n";
    cout << "_______________________________________________________\n";
    for (int i = 0; i < 10; i++)
    {
        cout << NameOfId(P.Inventory_Iditem_OF_slot(i));
        if (P.Inventory_Count_of_items(i) > 1)
        {
            cout << " " << P.Inventory_Count_of_items(i);
        }       
        cout << "\n";
    }
    cout << "_______________________________________________________\n";
    cout << "\n";
}

int Find_slotId_by_iditem(Player P, int item_id)
{
    int cur_slot = -1;
    for (int i = 0; i < 10; i++)
    {
        if (P.Inventory_Iditem_OF_slot(i) == item_id)
        {
            cur_slot = i;
        }
    }
    return cur_slot;
}

string NameOfId(int i)
{

    if (i == 0) return "";
    if (i == 1) return "�����";
    if (i == 2) return "������";
    if (i == 3) return "���� �����";
    if (i == 4) return "������ �����";
    if (i == 5) return "������ �����";
    if (i == 6) return "�����";
    if (i == 7) return "���� �����";
    if (i == 8) return "���� �����";
}