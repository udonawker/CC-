#include <iostream>
#include <thread>
#include <future>
#include <utility>
#include <time.h>

// g++ -std=c++11 -o threadtest threadtest.cpp -lpthread
// std::future https://cpprefjp.github.io/reference/future/future.html

// futureとpromiseのあれこれ（理論編）https://yohhoy.hatenadiary.jp/entry/20120131/p1
// futureとshared_future https://yohhoy.hatenadiary.jp/entry/20120201/p1
// C++11における同期処理(std::mutex, std::unique_guard, std::lock_guard, std::condition_variable) https://qiita.com/termoshtt/items/c01745ea4bcc89d37edc

class Test {
public:
    Test() = default;

    std::future<int> threadtest(int dur, int callID)
    {
        std::promise<int> promise;
        std::future<int> future = promise.get_future();
        std::thread(
            [](std::promise<int>&& p, int duration, int id) {
                std::this_thread::sleep_for(std::chrono::seconds(duration));
                p.set_value(id);
            },
            std::move(promise),
            dur,
            callID)
            .detach();
    
        return future;
    }
};

void currentTime()
{
    struct tm lt{};
    time_t now = ::time(NULL);
    ::localtime_r(&now, &lt);

    ::printf(
        "%d:%d:%d\n",
        lt.tm_hour,
        lt.tm_min,
        lt.tm_sec
        );
}

int main()
{
    Test test;

    currentTime();
    std::future<int> future = test.threadtest(10,1);
    //future.wait();
    
    currentTime();

    ::printf("future.get = %d\n", future.get());
}

/*
joinとdetach
std::threadを一度作成すると、必ずjoin()またはdetach()を呼ばなければなりません。さもなくば、std::terminateでジ・エンドです。
また、一度join()またはdetach()が呼び出されて、空の状態になったstd::threadに対して、再度join()、detach()を呼び出してはなりません。
*/
/*
join
join()を呼び出すと、join()が呼び出されたスレッド(上の例ではt2)の処理が終了するまで、join()を呼び出したスレッドはブロックされます。上の例だと、t2の処理が終わるまで、iの出力が行われることはありません。
また、join()を呼び出して処理が終了したthreadオブジェクトは、どのスレッドもささない空のthreadオブジェクトになります。
threadオブジェクトがjoin()を呼び出せる状態かどうかは、joinable()メンバ関数で確認できます。
*/
/*
detach
detach()を呼び出すと、threadオブジェクトとスレッドの関連を切り離すことができます。切り離されたthreadオブジェクトは、join()の呼び出し後と同様に、何もささない空のthreadオブジェクトとなります。また、切り離されたスレッドは、そのまま処理が続行されますが、他のスレッドから一切干渉することができなくなります。
threadオブジェクトがdetach()を呼び出せる状態かどうかは、join()同様、joinable()メンバ関数で確認できます。
*/