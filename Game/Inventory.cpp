#include <iostream>
#include "Inventory.h"

using namespace std;

void ShowInventory(Player& P)
{
    cout << "\t INVENTORY \n";
    cout << "_______________________________________________________\n";
    for (int i = 0; i < 10; i++)
    {
        cout << NameOfId(P.Inventory_Iditem_OF_slot(i));
        if (P.Inventory_Count_of_items(i) > 0)
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
    switch (i)
    {
    case 0:
        return "";
        break;
    case 1:
        return "палка";
        break;
    case 2:
        return "трава";
        break;
    default:
        return "хз че за предмет";
        break;
    }
}