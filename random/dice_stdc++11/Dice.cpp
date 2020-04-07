#include "Dice.h"

Dice& Dice::getInstance()
{
    static Dice instance;
    return instance;
}

Dice::Dice()
    : m_seedGen()
    , m_engine(m_seedGen())
    , m_distribution(1, 6)
{
}

int Dice::cast()
{
    return m_distribution(m_engine);
}

