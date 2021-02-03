#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
//nclude <iomanip>
#include <chrono>
#include <sstream>
#include <ctime>

// $ g++ prog.cc -Wall -Wextra -std=c++11

class Timer {
    std::mutex mtx_;
    std::condition_variable cond_;

    bool is_wait_ = true;

public:
    void notify_end()
    {
        {
            std::lock_guard<std::mutex> lk(mtx_);
            is_wait_ = false;
        }

        cond_.notify_all();
    }

    bool wait_x(std::chrono::seconds seconds)
    {
      std::unique_lock<std::mutex> lk(mtx_);
      bool is_wait = is_wait_;

      // データの準備ができるまで待機してから処理する
      if (is_wait) {
          // 述語を指定しないバージョン
          // 3秒でタイムアウト
          std::cv_status result = cond_.wait_for(lk, seconds);
          switch (result) {
              case std::cv_status::timeout:
                  break;
              case std::cv_status::no_timeout:
                  is_wait = false;
                  break;
          }
      }
      return is_wait;
    }
    bool wait(std::chrono::seconds seconds)
    {
        std::unique_lock<std::mutex> lk(mtx_);

        return cond_.wait_for(lk, seconds, [this] { return !is_wait_; });
    }
};

static std::string getTimeStamp()
{
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    
    std::stringstream ss;
    std::array<char, 1024> buffer {'\0'};
    std::strftime(buffer.data(), buffer.size(), "%Y%m%d_%H%M%S", localtime(&now_c));
    ss << buffer.data();
    //ss << std::put_time(localtime(&now_c), "%Y%m%d_%H%M%S"); gcc 5以上
    return ss.str();
}

int main()
{
    Timer t;
    std::function<void(int, std::chrono::seconds)> thread_func = [&](int idx, std::chrono::seconds seconds) {
        while (!t.wait(seconds)) {
            std::cout << "index : " << idx << " wait " << getTimeStamp() << std::endl;
        }
        std::cout << "index : out " << std::endl;
    };
    
    std::thread t1(thread_func, 1, std::chrono::seconds(1));
    std::thread t2(thread_func, 2, std::chrono::seconds(2));
    std::thread t3(thread_func, 3, std::chrono::seconds(3));

    std::this_thread::sleep_for(std::chrono::seconds(15));
    t.notify_end();
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}

/*
index : 1 wait 20210203_180230
index : 2 wait 20210203_180231
index : 1 wait 20210203_180231
index : 3 wait 20210203_180232
index : 1 wait 20210203_180232
index : 2 wait 20210203_180233
index : 1 wait 20210203_180233
index : 1 wait 20210203_180234
index : 3 wait 20210203_180235
index : 2 wait 20210203_180235
index : 1 wait 20210203_180235
index : 1 wait 20210203_180236
index : 1 wait 20210203_180237
index : 2 wait 20210203_180237
index : 3 wait 20210203_180238
index : 1 wait 20210203_180238
index : 1 wait 20210203_180239
index : 2 wait 20210203_180239
index : 1 wait 20210203_180240
index : 3 wait 20210203_180241
index : 2 wait 20210203_180241
index : 1 wait 20210203_180241
index : 1 wait 20210203_180242
index : 2 wait 20210203_180243
index : 1 wait 20210203_180243
index : out 
index : out 
index : out 
0
*/
