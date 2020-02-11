#include <iostream>
#include <memory>
// g++ -std=c++14 -o dynamic_static_cast dynamic_static_cast.cpp
class Base
{
public:
    Base() = default;
    Base(int data) : m_data(data) {}
    virtual ~Base() {}
    
    int GetData() const { return m_data; }
    
private:
    int m_data = 0;
};

class BaseDriver : public Base
{
public:
    BaseDriver() = default;
    BaseDriver(int data) : Base(data) { m_dataNew = data * data; }
    virtual ~BaseDriver() {}
    
    int GetDataNew() const { return m_dataNew; }
    
private:
    int m_dataNew = 0;
};

int main(int argc, char* argv[])
{
    std::unique_ptr<Base> base = std::make_unique<BaseDriver>(5);
    
    BaseDriver* driverStatic  = static_cast<BaseDriver *>(base.get());
    BaseDriver* driverDynamic = dynamic_cast<BaseDriver *>(base.get());
    
    std::cout << "driverStatic  GetDataNew() : " << driverStatic->GetDataNew() << std::endl;
    std::cout << "driverDynamic GetDataNew() : " << driverDynamic->GetDataNew() << std::endl;
    
    Base baseNotPtr = BaseDriver(5);
    Base& baseRef   = baseNotPtr;
    
    //std::cout << "driverNotPtr  GetDataNew() : " << dynamic_cast<BaseDriver>(baseNotPtr).GetDataNew() << std::endl;
    // dynamic_static_cast.cpp:43:88: error: cannot dynamic_cast ‘baseNotPtr’ (of type ‘class Base’) to type ‘class BaseDriver’ (target is not pointer or reference)
    // iverNotPtr  GetDataNew() : " << dynamic_cast<BaseDriver>(baseNotPtr).GetDataNew() << std::endl;
    
    // std::cout << "driverNotPtr  GetDataNew() : " << dynamic_cast<BaseDriver&>(baseNotPtr).GetDataNew() << std::endl;
    // dynamic_static_cast.cpp:42:89: warning: dynamic_cast of ‘Base baseNotPtr’ to ‘class BaseDriver&’ can never succeed 
    // verNotPtr  GetDataNew() : " << dynamic_cast<BaseDriver&>(baseNotPtr).GetDataNew() << std::endl;
    
    
    // std::cout << "driverNotPtr  GetDataNew() : " << dynamic_cast<BaseDriver&>(baseRef).GetDataNew() << std::endl;
    // compile ok -> Execute
    // terminate called after throwing an instance of 'std::bad_cast'
    // what():  std::bad_cast
    // Aborted (core dumped)
    
    //std::cout << "driverNotPtr  GetDataNew() : " << dynamic_cast<BaseDriver*>((Base*)&baseNotPtr)->GetDataNew() << std::endl;
    // compile ok -> Execute
    // Segmentation fault (core dumped)
    
    //std::cout << "driverNotPtr  GetDataNew() : " << dynamic_cast<BaseDriver*>((BaseDriver*)&baseNotPtr)->GetDataNew() << std::endl;
    // compile ok -> Execute
    // driverNotPtr  GetDataNew() : 32525 ★不定の値
    
    //Base* basePtr = &baseNotPtr;
    //std::cout << "driverNotPtr  GetDataNew() : " << dynamic_cast<BaseDriver*>(basePtr)->GetDataNew() << std::endl;
    
    Base* basePtr = &baseNotPtr;
    std::cout << "driver dynamic cast : " << std::hex << dynamic_cast<BaseDriver*>(basePtr) << std::endl;
    // compile ok -> Execute
    // driver dynamic cast : 0
}
