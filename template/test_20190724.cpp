#include "test_20190724.h"
#include <mutex>

struct Test::TestTest {
    void initSharedMemory();
};

Test::Test()
: m_testData{std::make_unique<Test::TestTest>()}
{
}

void Test::TestTest::initSharedMemory()
{
    ::printf("m_testData->initSharedMemory();\n");
}

bool Test::configureReadOnly()
{
    m_testData->initSharedMemory();
}
