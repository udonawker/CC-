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
