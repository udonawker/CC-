#ifndef _STATIC_TEST_CONST_NG_
#define _STATIC_TEST_CONST_NG_

class StaticTestConstNg
{
public:
    static int Get();// const;
    static int Set(int set);
    
private:
    StaticTestConstNg() = default;
    
};

#endif //_STATIC_TEST_CONST_NG_
/*
++ -std=c++11 -o static_test_constng static_test_constng.cpp static_test_constng_main.cpp
In file included from static_test_constng.cpp:1:0:
static_test_constng.h:7:22: error: static member function ‘static int StaticTestConstNg::Get()’ cannot have cv-qualifier
     static int Get() const;
                      ^~~~~
static_test_constng.cpp:6:30: error: static member function ‘static int StaticTestConstNg::Get()’ declared with type qualifiers
 int StaticTestConstNg::Get() const
                              ^~~~~
In file included from static_test_constng_main.cpp:2:0:
static_test_constng.h:7:22: error: static member function ‘static int StaticTestConstNg::Get()’ cannot have cv-qualifier
     static int Get() const;
                      ^~~~~
[root@FCS-J1H1MX2 static_test]#
*/