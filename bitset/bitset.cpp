#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <bitset>
//#include "bitset_iterator.h"

/*
bitset_iterator
https://python5.com/q/mgbpzxxk
https://gist.github.com/diegum/c719a91065b8b5915ecd484d0584269a
*/

int main()
{
    std::bitset<8> bs{ "01010101" };
    std::bitset<32> bs2{ 0b10101010101010101010101010101010 };
    
    for (std::size_t i = 0; i < bs.size(); ++i) {
        //std::cout << bs[i] << '\n';
        if (bs[i]) {
            std::cout << "bit : " << i << std::endl;
        }
    }
    
    return 0;
}
/*
bit : 0
bit : 2
bit : 4
bit : 6
*/
