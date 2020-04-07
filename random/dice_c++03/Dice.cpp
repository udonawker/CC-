#include "Dice.h"
#include <stdlib.h>
#include <time.h>

Dice Dice::instance;

Dice& Dice::getInstance()
{
    return instance;
}

Dice::Dice()
{
    ::srand((unsigned)time(NULL));
}

int Dice::cast()
{
    return ::rand() % 6 + 1;
}

