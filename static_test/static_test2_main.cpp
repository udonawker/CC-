#include "static_test2.h"
#include <iostream>

// g++ -o static_test2_main static_test2.cpp static_test2_main.cpp

int main(int argc, char* argv[])
{
    StaticTest2 instance1 = StaticTest2::GetInstance(1);
    std::cout << "1 getinstance size = " << instance1.GetSize() << std::endl;
    StaticTest2 instance2 = StaticTest2::GetInstance(2);
    std::cout << "2 getinstance size = " << instance2.GetSize() << std::endl;
    StaticTest2 instance3 = StaticTest2::GetInstance(3);
    std::cout << "3 getinstance size = " << instance3.GetSize() << std::endl;
}
/*
# ./static_test2_main
Fri Oct  4 17:25:53 2019
1570177553 seconds since the Epoch
1 getinstance size = 1
2 getinstance size = 1
3 getinstance size = 1
*/