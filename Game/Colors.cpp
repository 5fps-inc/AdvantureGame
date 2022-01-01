#include "Colors.h"
#include "game_func.h"

int SetRandomColorOfRare()
{
    int s = RandNum(1, 31);
    if (s <= 16)
    {
        return CL_BLACK_GREY;
    }
    if ((s > 16) && (s <= 24))
    {
        return CL_BLACK_GREEN;
    }
    if ((s > 24) && (s <= 28))
    {
        return CL_BLACK_BLU;
    }
    if ((s > 28) && (s <= 30))
    {
        return CL_BLACK_PURP;
    }
    if ((s > 30) && (s <= 31))
    {
        return CL_BLACK_YELLOW;
    }
    else
    {
        return CL_BLACK_WHITE;
    }
}