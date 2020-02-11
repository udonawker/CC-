#ifndef _TEST_20190724_H_
#define _TEST_20190724_H_

#include <string>
#include <memory>
#include <functional>

// c - T���O���錾�ł���std :: unique_ptr���g�p�ł��Ȃ�
// https://codeday.me/jp/qa/20190318/432018.html
// c++�Ɋւ���l�I�^��Ƃ���ɑΉ����铚��
// https://qiita.com/eisoku9618/items/4401d933a7a43152ec7a

struct Test {
public:
    bool    configureReadOnly();
    void    xxx();//��`�݂̂Ŏ������Ȃ��Ă��֐����g�p���Ȃ���΃R���p�C���G���[�ɂ͂Ȃ�Ȃ��B(�g�p����ƃG���[�ɂȂ�)
    
    Test();
    
protected:
    struct TestTest;
    // std::unique_ptr<Test::TestTest> m_testData{nullptr}; �R���p�C���ʂ�Ȃ�
    /*
    * In file included from /usr/include/c++/7/memory:80:0,
    *                  from test_20190724.h:5,
    *                  from test_20190724_exec.cpp:2:
    * /usr/include/c++/7/bits/unique_ptr.h: In instantiation of �evoid std::default_delete<_Tp>::operator()(_Tp*) const [with _Tp = Test::TestTest]�f:
    * /usr/include/c++/7/bits/unique_ptr.h:268:17:   required from �estd::unique_ptr<_Tp, _Dp>::~unique_ptr() [with _Tp = Test::TestTest; _Dp = std::default_delete<Test::TestTest>]�f
    * test_20190724.h:17:97:   required from here
    * /usr/include/c++/7/bits/unique_ptr.h:76:22: error: invalid application of �esizeof�f to incomplete type �eTest::TestTest�f
    *   static_assert(sizeof(_Tp)>0,//)
    */
    std::unique_ptr<Test::TestTest, std::function<void(Test::TestTest*)>> m_testData{nullptr};
        // �R���p�C���ʂ�
    
    void initSharedMemory();//��`�݂̂Ŏ������Ȃ��Ă��֐����g�p���Ȃ���΃R���p�C���G���[�ɂ͂Ȃ�Ȃ��B(�g�p����ƃG���[�ɂȂ�)
};

#endif
