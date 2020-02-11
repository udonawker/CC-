#include "static_test_constng.h"

#include <iostream>
#include <random>

int StaticTestConstNg::Get()// const
{
    std::random_device rnd;     // 非決定的な乱数生成器を生成
    std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
    std::uniform_int_distribution<> rand100(0, 99);        // [0, 99] 範囲の一様乱数
    return rand100(mt);
}

int StaticTestConstNg::Set(int set)
{
    return set;
}
