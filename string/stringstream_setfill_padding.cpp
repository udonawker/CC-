#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
 
int main() {
    std::stringstream ss;
 
    int year = 1999;
    int month = 5;
 
    ss << "年：" << std::setw(4) << std::setfill('0') << year << "n";
    ss << "月：" << std::setw(4) << month;
 
    std::cout << ss.str() << "n";
 
    return 0;
}
/*
実行結果：

年：1999
月：0005
*/
