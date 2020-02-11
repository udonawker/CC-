#ifndef _TEST_20190724_H_
#define _TEST_20190724_H_

#include <string>
#include <memory>
#include <functional>

// c - Tが前方宣言であるstd :: unique_ptrを使用できない
// https://codeday.me/jp/qa/20190318/432018.html
// c++に関する個人的疑問とそれに対応する答え
// https://qiita.com/eisoku9618/items/4401d933a7a43152ec7a

struct Test {
public:
    bool    configureReadOnly();
    void    xxx();//定義のみで実装しなくても関数を使用しなければコンパイルエラーにはならない。(使用するとエラーになる)
    
    Test();
    
protected:
    struct TestTest;
    // std::unique_ptr<Test::TestTest> m_testData{nullptr}; コンパイル通らない
    /*
    * In file included from /usr/include/c++/7/memory:80:0,
    *                  from test_20190724.h:5,
    *                  from test_20190724_exec.cpp:2:
    * /usr/include/c++/7/bits/unique_ptr.h: In instantiation of ‘void std::default_delete<_Tp>::operator()(_Tp*) const [with _Tp = Test::TestTest]’:
    * /usr/include/c++/7/bits/unique_ptr.h:268:17:   required from ‘std::unique_ptr<_Tp, _Dp>::~unique_ptr() [with _Tp = Test::TestTest; _Dp = std::default_delete<Test::TestTest>]’
    * test_20190724.h:17:97:   required from here
    * /usr/include/c++/7/bits/unique_ptr.h:76:22: error: invalid application of ‘sizeof’ to incomplete type ‘Test::TestTest’
    *   static_assert(sizeof(_Tp)>0,//)
    */
    std::unique_ptr<Test::TestTest, std::function<void(Test::TestTest*)>> m_testData{nullptr};
        // コンパイル通る
    
    void initSharedMemory();//定義のみで実装しなくても関数を使用しなければコンパイルエラーにはならない。(使用するとエラーになる)
};

#endif
