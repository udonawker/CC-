#pragma once
#include <random>

class Dice {
public:
    static Dice& getInstance();

public:
    virtual ~Dice() {}

public:
    Dice(const Dice&) = delete;
    Dice(Dice&&) = delete;
    Dice& operator=(const Dice&) = delete; 
    Dice& operator=(Dice&&) = delete;

public:
    int cast();

private:
    Dice();

private:
    std::random_device m_seedGen;
    std::default_random_engine m_engine;
    std::uniform_int_distribution<> m_distribution;
    // std::default_random_engine m_engine{m_seedGen()};
    // std::uniform_int_distribution<> m_distribution{1, 6};
};
