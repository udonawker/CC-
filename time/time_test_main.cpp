#include <array>
#include <ctime>
#include <iostream>

#include <time.h>

// g++ -o time_test_main time_test_main.cpp

std::string Now1()
{
    std::time_t t = std::time(nullptr);
    return std::string(std::asctime(std::localtime(&t)));
}

std::string Now2()
{
    std::time_t t = std::time(nullptr);
    //std::tm tm = *std::localtime(&t));
    
    std::array<char, 256> buffer;
    std::strftime(&buffer.at(0), buffer.size(), "%Y%m%d%H%M%S", std::localtime(&t));
    return std::string(&buffer.at(0));
}

std::string Now3()
{
    std::time_t t = std::time(nullptr);
    struct tm tm{};
    localtime_r(&t, &tm);
    
    std::array<char, 256> buffer;
    std::strftime(&buffer.at(0), buffer.size(), "%Y%m%d%H%M%S", &tm);
    return std::string(&buffer.at(0));
}

int main(int argc, char* argv[])
{
    std::cout << Now1() << std::endl;
    std::cout << Now2() << std::endl;
    std::cout << Now3() << std::endl;
}


// strftime https://ja.cppreference.com/w/cpp/chrono/c/strftime
/*
localtime_rに代わるC 11
https://codeday.me/jp/qa/20181230/120787.html
https://code-examples.net/ja/q/6f99ff
*/