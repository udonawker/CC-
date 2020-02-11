#include <fstream>
#include <stdio.h>
#include <memory>
#include <iostream>
// g++ -std=c++14 -o filestream_pointer_test filestream_pointer_test.cpp
int main(int argc, char* argv[])
{
    std::unique_ptr<std::ifstream> ifs = std::make_unique<std::ifstream>("aaa.txt");
    std::string str;
    
    *ifs >> str;

    std::cout << "aaa.txt = " << str << std::endl;
}

