#ifndef INVENTORY_H
#define INVENTORY_H
#include "Player.h"
#include <string>

void ShowInventory(Player& P);

int Find_slotId_by_iditem(Player P, int item_id);

string NameOfId(int i);

#endif // !INVENTORY_H

