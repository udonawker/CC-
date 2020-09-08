[AkiyukiOkayasu getTimeStamp.cpp](https://gist.github.com/AkiyukiOkayasu/b4051e942e40d53c7463f4057146f7cc)<br/>

<pre>
#include &lt;string&gt;
#include &lt;chrono&gt;
#include &lt;sstream&gt;
#include &lt;iomanip&gt;

std::string getTimeStamp()
{
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(localtime(&now_c), "%Y%m%d_%H%M%S");
    return ss.str();
}

//----------出力例----------
//20171231_145030

//2017年12月31日 14時50分30秒のこと
</pre>

ミリ秒も
<pre>
#include &lt;array&gt;
#include &lt;iostream&gt;
#include &lt;sstream&gt;
#include &lt;chrono&gt;
#include &lt;ctime&gt;
#include &lt;iomanip&gt;
#include &lt;time.h&gt;

using namespace std::chrono;

int main()
{
    //std::chrono::high_resolution_clock::time_point p = std::chrono::high_resolution_clock::now();
    std::chrono::system_clock::time_point p = std::chrono::system_clock::now();

    std::chrono::milliseconds ms = std::chrono::duration_cast<milliseconds>(p.time_since_epoch());

    std::chrono::seconds s = duration_cast<seconds>(ms);
    std::time_t t = s.count();
    std::size_t fractional_seconds = ms.count() % 1000;

    auto now_tt = std::chrono::system_clock::to_time_t(p);
    std::stringstream ss;
#if __GNUC__ >= 5 // GCC5.0以上
// std::get_timeおよびstd::put_timeはGCC5以上
    ss << std::put_time(localtime(&now_tt), "%Y%m%d_%H%M%S");
#else
    //struct tm now_tm{};
    //localtime_s(&now_tm, &now_tt);
    std::array&lt;char, 1024&gt; buffer {};
    std::strftime(buffer.data(), buffer.size(), "%Y%m%d_%H%M%S", localtime(&now_tt));
    ss << buffer.data();
#endif
    std::cout << ss.str() << "." << fractional_seconds << std::endl;
}
// g++ -std=c++11 -o gettime getTimeStampChronoHighResolution.cpp
// 20200908_133605.641
</pre>
