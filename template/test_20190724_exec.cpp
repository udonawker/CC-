#include <iostream>
#include "test_20190724.h"

// g++ -std=c++14 -o test_20190724 test_20190724.cpp test_20190724_exec.cpp

int main(int argc, char* argv[])
{
    Test t;
    
    t.configureReadOnly();
    ::printf("test_20190724\n");
    
    return 0;
}
