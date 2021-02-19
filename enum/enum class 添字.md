## [配列のインデックスに列挙型を使う](https://qiita.com/SaitoAtsushi/items/b7f2aef6df10ba5da77d)
## [ENUMとINTへの変換(列挙型をうまくつかってインデックスにする)](https://qiita.com/KawabataLemon/items/4451a90158ff523539bf)

```
// g++ prog.cc -Wall -Wextra -std=c++11
#include <iostream>

enum class TestType : int {
    kType1,
    kType2,
    kType3,
    kTypeNum
};

int main()
{
    int tests[static_cast<int>(TestType::kTypeNum)] {1, 2, 3};
    for (auto&& i : tests) {
        std::cout << "test : " << i << std::endl;
    }
}
/*
test : 1
test : 2
test : 3
*/
```
