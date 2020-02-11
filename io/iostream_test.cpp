#include <fstream>
#include <istream>
#include <sstream>
#include <stdio.h>

#include <memory>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
    std::unique_ptr<std::iostream> ptr=std::make_unique<std::stringstream>();

    ::printf("good ? : %d\n", ptr->good());

    *ptr << "HelloWorld?";


    ::printf("echo1 %s\n", dynamic_cast<std::stringstream*>(ptr.get())->str().c_str());
    
    std::string str;
    *ptr >> str;
    std::string str2(str.begin(), str.end());
    ::printf("echo2 %s\n", str2.c_str());
    
    pid_t pid = getpid();
    ::printf("pid = %d\n", pid);

    char buffer[1024] {};
    ::sprintf(buffer, "/proc/%u/temp.txt", (unsigned)pid);

    std::ofstream ofs(buffer);

    ::printf("file=%s good=%d\n", buffer, ofs.good());
    ofs << "abc";

    ::getchar();

}
