#include <cstdint>
#include <iostream>

// g++ -std=c++11 -o bit_field_test bit_field_test.cpp

struct bit_field {
    std::uint64_t    a : 10;
    std::uint64_t    b : 10;
    std::uint64_t    c : 10;
    std::uint64_t    d : 10;
    std::uint64_t      : 24;
};

int main(int argc, char* argv[]) {
    std::uint8_t  src[8]{0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE};
    std::uint16_t dst[4]{};
    const bit_field* bf = reinterpret_cast<bit_field*>(src);

    dst[0] = bf->a;
    dst[1] = bf->b;
    dst[2] = bf->c;
    dst[3] = bf->d;

    std::cout << std::hex;
    std::cout << "0 = 0x" << dst[0] << std::endl;
    std::cout << "1 = 0x" << dst[1] << std::endl;
    std::cout << "2 = 0x" << dst[2] << std::endl;
    std::cout << "3 = 0x" << dst[3] << std::endl;
}

//0 = 0x2ee
//1 = 0x3bb
//2 = 0x2ee
//3 = 0x3bb
