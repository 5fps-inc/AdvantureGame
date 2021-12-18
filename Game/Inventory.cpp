#include <iostream>
#include "Inventory.h"

using namespace std;

void ShowInventory(Player& P)
{
    cout << "\t »Ќ¬≈Ќ“ј–№ \n";
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
    if (i == 1) return "палка";
    if (i == 2) return "листик";
    if (i == 3) return "лапа зайца";
    if (i == 4) return "Ўерсть мишки";
    if (i == 5) return " оготь мишки";
    if (i == 6) return "ягода";
    if (i == 7) return "ћ€со зайца";
    if (i == 8) return "ћ€со мишки";
}