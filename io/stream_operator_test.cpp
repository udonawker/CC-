#include <fstream>
#include <stdio.h>
#include <memory>
#include <iostream>
#include <string_view>

class StreamTest
{
public:
    StreamTest& operator<<(StreamTest& (*pf)(StreamTest&)) {
        (*pf)(*this);
        return *this;
    }
};

StreamTest& endl(StreamTest& os) {
  std::cout << "operator<<(StreamTest& (*pf)(StreamTest&))" << std::endl;
}
// g++ -std=c++17 -o stream_operator_test stream_operator_test.cpp
int main(int argc, char* argv[])
{
    StreamTest test;

    test << endl;

    //std::cout << "aaa.txt = " << str << std::endl;
}

