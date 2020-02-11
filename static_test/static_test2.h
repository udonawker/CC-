#ifndef _STATIC_TEST2_H_
#define _STATIC_TEST2_H_

class StaticTest2
{
public:
    static StaticTest2& GetInstance(int size);
    
    StaticTest2(int size);
    ~StaticTest2();
    
    int GetSize() const { return m_size; }
    
private:
    void Now();
    
    int m_size{0};
};

#endif // _STATIC_TEST2_H_
