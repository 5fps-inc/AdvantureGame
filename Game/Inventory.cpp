#include <iostream>
#include "Inventory.h"

using namespace std;

void ShowInventory(Player P)
{
    cout << "\t INVENTORY \n";
    cout << "_______________________________________________________\n";
    int emptySlots = 0;
    for (int i = 0; i < 10; i++)
    {
        if (P.Inventory_Id_OF_slot(i) == 0)
        {
            cout << "";
            emptySlots += 1;
        }
        else
        {
            if (P.Inventory_Id_OF_slot(i) == 1)
            {
                cout << "ÏÀËÊÀ" << "(" << P.Inventory_Count_of_items(i) << ")";
            }
        }
        cout << "\n";
    }
    if (emptySlots == 10)
    {
        cout << "          ÂÅÑÜ ÈÍÂÅÍÒÀÐÜ ÏÓÑÒÎÉ\n";
    }
    cout << "_______________________________________________________\n";
    cout << "\n";
}
