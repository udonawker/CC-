#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <string>

void Wait();

int main(int argc, const char* argv[])
{
    std::string filename("test_temp.txt");
    
    pid_t pid = getpid();
    
    std::ofstream ofs(filename);
    
    std::cout << "pid = " << pid << std::endl;
    std::cout << "tempfile open : " << filename << std::endl;
    std::cout << "opened?       : " << ofs.is_open() << std::endl;
    
    Wait();
    
    std::cout << "unlink : " << filename << "(" << unlink(filename.c_str()) << ")" << std::endl;
    
    Wait();
    
    std::cout << "is_open " << ofs.is_open() << std::endl;
    
    Wait();
    
    ofs << "aaaaa" << std::endl;
    std::cout << "tellp   " << ofs.tellp() << std::endl;
    std::cout << "good?   " << ofs.good() << std::endl;
    
    Wait();
    
    struct stat st {};
    std::cout << "stat result : " << stat(filename.c_str(), &st) << std::endl;
    
    Wait();
}

void Wait()
{
    std::cout << "Enter Key" << std::endl;
    //int wait = 0;
    //std::cin >> wait;
    getchar();
}
