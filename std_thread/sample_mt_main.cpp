#include "sample_mt.h"

#include <chrono>
#include <iostream>

// g++ -std=c++11 -o sample_mt_main sample_mt.cpp sample_mt_main.cpp -lpthread

int main(int argc, char* argv[])
{
    auto begin = std::chrono::system_clock::now();
    std::chrono::seconds sec(5);
    
    SampleMT sample;
    auto future = sample.AddMT(sec, 2, 3);
    int result = future.get();
    
    auto end = std::chrono::system_clock::now();
    auto diff = end - begin;
    
    std::cout << "result = " << result << std::endl;
    std::cout << "elapsed time = "
              << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
              << " msec."
              << std::endl;
}
