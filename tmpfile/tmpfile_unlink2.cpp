#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void Wait();

int main(int argc, const char* argv[])
{
    std::string filename("test_temp2.txt");
    
    pid_t pid = getpid();
    
    std::ofstream ofs(filename);
    std::string input("aaaa");
    
    std::cout << "pid = " << pid << std::endl;
    std::cout << "tempfile open : " << filename << std::endl;
    std::cout << "opened?       : " << ofs.is_open() << std::endl;
    std::cout << "<< " << input << "       : " << ofs.is_open() << std::endl;
    ofs << input;
    ofs.close();
    std::cout << "close         : " << filename << std::endl;
    
    Wait();
    
    std::fstream fs(filename, std::ios_base::in | std::ios_base::out);
    std::cout << "tempfile open : " << filename << std::endl;
    std::cout << "opened?       : " << fs.is_open() << std::endl;
    std::cout << "tellp         : " << fs.tellp() << std::endl;
    std::cout << "tellg         : " << fs.tellg() << std::endl;
    std::cout << "good?         : " << fs.good() << std::endl;
    std::fstream::pos_type pos = fs.tellg();
    
    Wait();
    
    std::cout << "unlink        : " << filename << "(" << unlink(filename.c_str()) << ")" << std::endl;
    struct stat st {};
    std::cout << "stat result : " << stat(filename.c_str(), &st) << std::endl;
    //fs << "bbbbbbbbbbb";////
    Wait();
    
    std::cout << "opened?       : " << fs.is_open() << std::endl;
    std::string get;
    
    fs.seekp(pos);
    fs >> get;
    pos = fs.tellp();
    
    std::cout << "get string    : " << get << std::endl;
    std::cout << "tellp         : " << fs.tellp() << std::endl;
    std::cout << "tellg         : " << fs.tellg() << std::endl;
    std::cout << "pos           : " << pos << std::endl;
    std::cout << "good?         : " << fs.good() << std::endl;
    
    Wait();
    
    std::string append("bbb");
    std::cout << "append        : " << append << std::endl;
    
    fs.clear();
    fs.seekp(pos);
    std::cout << "seekp         : " << pos << std::endl;
    std::cout << "tellp         : " << fs.tellp() << std::endl;
    fs << append;
    pos = fs.tellp();
    std::cout << "tellp         : " << fs.tellp() << std::endl;
    std::cout << "tellg         : " << fs.tellg() << std::endl;
    std::cout << "pos           : " << pos << std::endl;
    std::cout << "good?         : " << fs.good() << std::endl;
    
    Wait();
    
    fs.clear();
    fs.seekg(0, std::fstream::end);
    std::fstream::pos_type end = fs.tellg();
    fs.clear();
    fs.seekg(0, std::fstream::beg);
    std::fstream::pos_type begin = fs.tellg();
    size_t file_size = static_cast<size_t>(end - begin);
    std::vector<std::uint8_t> v(file_size);
    fs.read((char *)(&v.at(0)), file_size);
    
    //std::stringstream ss(fs.rdbuf());
    std::istringstream iss(std::string((char *)(&v.at(0)), v.size()));
    
    std::cout << "file contents : " << iss.str();
    
    Wait();
}

void Wait()
{
    std::cout << "Enter Key" << std::endl;
    //int wait = 0;
    //std::cin >> wait;
    getchar();
}
