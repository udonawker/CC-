#include <fstream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::fstream fs;

    ::printf("good ? : %d\n", fs.good());

    fs.open("data.txt", std::ios_base::in | std::ios_base::out | std::ios_base::ate);

    ::printf("ate tellp = %u tellg = %u\n", fs.tellp(), fs.tellg());
    fs.close();
    fs.open("data.txt", std::ios_base::in | std::ios_base::out );
    ::printf("default tellp = %u tellg = %u\n", fs.tellp(), fs.tellg());
    fs.open("data.txt", std::ios_base::in | std::ios_base::out | std::ios_base::app);
    ::printf("app tellp = %u tellg = %u\n", fs.tellp(), fs.tellg());
}

