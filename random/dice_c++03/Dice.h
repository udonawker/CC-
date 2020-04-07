#pragma once

class Dice {
public:
    static Dice& getInstance();

public:
    virtual ~Dice() {}

public:
    int cast();

private:
    Dice();

private:
    static Dice instance;
};
