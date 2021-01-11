#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[])
{
    auto read_file = []( const std::string& path ){
        std::ifstream f(path);
        std::stringstream ss;
        ss << f.rdbuf();
        return ss.str();
    };
    
    auto read_file2 = []( const std::string& path ) -> std::string {
        std::ifstream f(path);
        std::stringstream ss;
        ss << f.rdbuf();
        return ss.str();
    };
    
    auto write_file = []( const std::string& path, const std::string& text ){
        std::ofstream outputfile(path, std::ios::app);
        outputfile << text << std::endl;
        outputfile.close();
    };
    
    auto write_file2 = []( const std::string& path, const std::string& text ) -> void {
        std::ofstream outputfile(path, std::ios::app);
        outputfile << text << std::endl;
        outputfile.close();
    };
    
    write_file("test.txt", "aaa");
    std::cout << read_file("test.txt");
    write_file2("test.txt", "bbb");
    std::cout << read_file2("test.txt");
    
    return 0;
}
/*
aaa
aaa
bbb
*/

/*
定数	説明
std::ios_base::app	各書き込みの前にストリームの最後までシーク
std::ios_base::binary	バイナリオープン
std::ios_base::in	読むためにファイルを開く
std::ios_base::out	書き込み用にファイルを開く
std::ios_base::trunc	開くときにストリームの内容を破棄します
std::ios_base::ate	オープン直後にストリームの端をシーク
*/
/*
https://programming.pc-note.net/cpp/filestream.html
std::ios::out 書き込みモード(デフォルト)
              書き込み時に、以前の内容は破棄される
std::ios::in  読み取りモード
std::ios::app 追記モード
              常にファイルの末尾に書き込み
              (append)
std::ios::ate オープンと同時にファイル末尾に移動
              任意の位置に移動可能
              std::ios::inと同時に指定する(後述)
              (at end)
std::ios::trunc 上書きモード
                ファイルを開いた時点で以前の内容が破棄される
                (truncate)
std::ios::binary バイナリモード
*/
