#include "Dice.h"
#include <iostream>
#include <string>

// g++ -std=c++03 -o DiceMain DiceMain.cpp Dice.cpp
int main(int argc, char* argv[])
{
    for (int i = 0; i < 10; i++) {
        std::cout << i << " = " << Dice::getInstance().cast() << std::endl;
    }

    return 0;
}

