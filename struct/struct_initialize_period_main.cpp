#include "struct_initialize_period.h"

// g++ -std=c++11 -o struct_initialize_period_main struct_initialize_period_main.cpp struct_initialize_period.cpp

int main()
{
    StructInitializePeriod test;
    test.printXXX();
    test.printYYY();
    return 0;
}
/*
$ ./struct_initialize_period_main 
XXX.x         = 1
XXX.buff[0].a = 1
XXX.buff[0].b = 2
XXX.buff[1].a = 10
XXX.buff[1].b = 20
YYY.x         = 3
YYY.buff[0].a = 3
YYY.buff[0].b = 4
YYY.buff[1].a = 30
YYY.buff[1].b = 40
*/

