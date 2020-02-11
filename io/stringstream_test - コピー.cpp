#include <fstream>
#include <sstream>
#include <cstring>
#include <stdio.h>
// g++ -std=c++14 -o stringstream_test stringstream_test.cpp
int main(int argc, char* argv[])
{
    std::stringstream ss(std::string("aaabbbccc"), std::stringstream::in | std::stringstream::out | std::stringstream::app);

    ::printf("good ? : %u\n", ss.good());
    ::printf("tellp = %u tellg = %u\n", ss.tellp(), ss.tellg());
    ::printf("str = %s size = %u\n", ss.str().c_str(), ss.str().size());
    
    std::string str(3, '\0');
    ss.read(&str[0], 3);
    
    ::printf("tellp = %u tellg = %u\n", ss.tellp(), ss.tellg());
    ::printf("str = %s size = %u\n", ss.str().c_str(), ss.str().size());
    
    ss << str;
    ::printf("tellp = %u tellg = %u\n", ss.tellp(), ss.tellg());
    ::printf("str = %s size = %u\n", ss.str().c_str(), ss.str().size());
    
    char buffer[128]{1,1,1};
    ss.write(buffer, 3);
    
    ::printf("tellp = %u tellg = %u\n", ss.tellp(), ss.tellg());
    ::printf("size = %u\n", ss.str().size());
    ::printf("str = %u\n", ss.str().c_str());
    
    char buffer2[128]{};
    //ss.read(buffer2, ss.str().size());
    std::memcpy(buffer, ss.str().c_str(), ss.str().size());
    
    ::printf("binary2 = ");
    for (int i = 0; i < static_cast<int>(ss.str().size()); i++) {
        ::printf("%X ", buffer2[i]);
    }
    ::printf("\n");
    
    ss.clear();
    ss.seekg(0, std::stringstream::end);
    std::stringstream::pos_type end = ss.tellg();
    ss.clear();
    ss.seekg(0, std::stringstream::beg);
    std::stringstream::pos_type begin = ss.tellg();
    size_t file_size = static_cast<size_t>(end - begin);
    ::printf("size = %u\n", file_size);
    
    char buffer3[128]{};
    ss.read(buffer3, file_size);
    
    ::printf("binary3 = ");
    for (int i = 0; i < static_cast<int>(file_size); i++) {
        ::printf("%X ", buffer3[i]);
    }
    ::printf("\n");
}

