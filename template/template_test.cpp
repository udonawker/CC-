#include <iostream>

template <typename TP1, typename TP2>
struct TestImpl
{

};

template <typename TP1>
struct TestImpl<TP1, TP1>
{

};
