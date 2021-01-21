#include <iostream>
#include <fstream>
#include <iterator>
#include <regex>
#include <string>
#include <random>
#include <sstream>
#include <iomanip>
#include <bitset>

void to_bit_string(std::string& bits)
{
    bits.erase(std::remove_if(bits.begin(), bits.end(), []( char ch ) { return !(ch == '0' || ch == '1'); }), bits.end());
}

int main()
{
    std::string bit_str("1111111111 1111111111 1111111111 1111111111");
    to_bit_string(bit_str);
    std::cout << bit_str << std::endl;
    std::bitset<40> bits(bit_str);
    std::cout << "bits size = " << bits.size() << std::endl;
    
    return 0;
}
/*
1111111111111111111111111111111111111111
bits size = 40
*/
