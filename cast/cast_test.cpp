#include <iostream>
#include <fstream>
#include <sstream>

class Base
{
public:
    Base(const Base& base) = default;
    
    int Get() const { return m_data; }
    
protected:
    
    Base(Base&& base)
    {
        m_data = base.m_data;
    }
    
    Base& operator=(Base&& base)
    {
        m_data = base.m_data;
    }
    
private:
    int m_data = 1;
};

class BaseDriver : public Base
{
public:
    BaseDriver()
    : Base(*this)
    {
    }
};

int main(int argc, char* argv[])
{
    //std::iostream stream = std::move(dynamic_cast<std::iostream>(&std::stringstream()));
    
    //stream = std::move(std::fstream("aaa.txt", std::io_base::in));
    
    //std::stringstream ss;
    //std::fstream stream = std::move(dynamic_cast<std::iostream&>(ss));
    
    std::iostream stream(std::fstream());
    std::iostream stream2(std::stringstream());
    std::iostream stream3(std::fstream());
    
    std::fstream fs = std::move(dynamic_cast<std::iostream>(stream3));
    
    //stream = std::move(dynamic_cast<std::iostream>(stream3));
    
    //Base base(BaseDriver());
    //BaseDriver driver;
}
