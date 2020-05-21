#include "struct_initialize_period.h"
#include <iostream>

const StructInitializePeriod::struct_x StructInitializePeriod::XXX = {
    .x = 1,
    .buff = {
        {
            .a = 1,
            .b = 2,
        },
        {
            .a = 10,
            .b = 20,
        }
    }
};

const StructInitializePeriod::struct_x StructInitializePeriod::YYY = {
    3,
    {
        {
            3,
            4
        },
        {
            30,
            40
        }
    }
};

void StructInitializePeriod::printXXX() {
    std::cout << "XXX.x         = " << XXX.x << std::endl;
    std::cout << "XXX.buff[0].a = " << XXX.buff[0].a << std::endl;
    std::cout << "XXX.buff[0].b = " << XXX.buff[0].b << std::endl;
    std::cout << "XXX.buff[1].a = " << XXX.buff[1].a << std::endl;
    std::cout << "XXX.buff[1].b = " << XXX.buff[1].b << std::endl;
}

void StructInitializePeriod::printYYY() {
    std::cout << "YYY.x         = " << YYY.x << std::endl;
    std::cout << "YYY.buff[0].a = " << YYY.buff[0].a << std::endl;
    std::cout << "YYY.buff[0].b = " << YYY.buff[0].b << std::endl;
    std::cout << "YYY.buff[1].a = " << YYY.buff[1].a << std::endl;
    std::cout << "YYY.buff[1].b = " << YYY.buff[1].b << std::endl;
}

