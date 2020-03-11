#include <iostream>
#include <string>
#include <utility>
#include <numeric>//std::accumulate()
#include <stdexcept>
#include <cctype>//std::isdigit()
// g++  -std=c++11 -o  lambda_test lambda_test.cpp
int calc_check_digit(const std::string& num) noexcept(false) {
    if (11 != num.length()) throw std::runtime_error("num.digit must be 11");
    const int remainder = std::accumulate(num.rbegin(), num.rend(), std::pair<int, int>{}, [](const std::pair<int, int>& s, const char& e){
        std::cout << "e=" << e << " first=" << s.first << " second=" << s.second << std::endl;
        if(!std::isdigit(e)) throw std::runtime_error("num.digit must be 11");
        const int n = s.second + 1;
        const int p = e - '0';
        const int q = (6 < n) ? n - 5 : n + 1;
        return std::pair<int, int>{s.first + p * q, n};
    }).first % 11;
    return (0 == remainder || 1 == remainder) ? 0 : 11 - remainder;
}

int main(int argc, char *argv[]) {
    int ret = calc_check_digit("12345678901");
    std::cout << "ret = " << ret << std::endl;
    return 0;
}

// e=1 first=0 second=0
// e=0 first=2 second=1
// e=9 first=2 second=2
// e=8 first=38 second=3
// e=7 first=78 second=4
// e=6 first=120 second=5
// e=5 first=162 second=6
// e=4 first=172 second=7
// e=3 first=184 second=8
// e=2 first=196 second=9
// e=1 first=206 second=10
// ret = 8
