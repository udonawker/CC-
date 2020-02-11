#include <iostream>
#include "static_test_constng.h"
// g++ -std=c++11 -o static_test_constng static_test_constng.cpp static_test_constng_main.cpp
int main(int argc, const char* argv[])
{
    std::cout << "StaticTestConstNg::Get() = " << StaticTestConstNg::Get() << std::endl;
}
