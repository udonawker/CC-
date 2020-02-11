#include "static_test2.h"
#include <iostream>
#include <ctime>

StaticTest2& StaticTest2::GetInstance(int size)
{
    static StaticTest2 instance{size};
    
    return instance;
}

StaticTest2::StaticTest2(int size)
: m_size(size)
{
    Now();
}

StaticTest2::~StaticTest2()
{
}

void StaticTest2::Now()
{
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
              << result << " seconds since the Epoch\n";
}
