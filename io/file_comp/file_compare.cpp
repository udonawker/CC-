#include <stdio.h>
//#include <tchar.h>
#include <iostream>
#include <fstream>

// g++ -std=c++11 -o file_compare file_compare.cpp

/*
    ファイルの比較
*/
/*
void compare_file
(
      std::wstring oFile1
    , std::wstring oFile2
)
{
    std::ifstream ifstr1( oFile1.c_str(), std::ios::binary );
    std::ifstream ifstr2( oFile2.c_str(), std::ios::binary );
 
    // ファイルの比較
    if ( std::equal( std::istreambuf_iterator<char>( ifstr1 )
        , std::istreambuf_iterator<char>(), std::istreambuf_iterator<char>( ifstr2 ) ) ) {
        std::wcout << L"一致しました" << std::endl;
    }
    else {
        std::wcout << L"一致しませんでした" << std::endl;
    }
}
*/

bool compare_file(std::string file1, std::string file2)
{
    std::ifstream ifstr1( file1.c_str(), std::ios::binary );
    std::ifstream ifstr2( file2.c_str(), std::ios::binary );
    
    // ファイルの比較
    return (std::equal(std::istreambuf_iterator<char>(ifstr1)
        , std::istreambuf_iterator<char>(), std::istreambuf_iterator<char>(ifstr2)));
}

//int _tmain
//(
//      int argc
//    , _TCHAR* argv[]
//)
int main(int argc, char* argv[])
{
    // 標準出力にユニコード出力する
    //setlocale( LC_ALL, "Japanese" );
 
    // ファイルを比較する
    //compare_file( L"file1.txt", L"file2.txt" );
 
    if (compare_file("file1.txt", "file2.txt"))
    {
        //std::wcout << L"一致しました" << std::endl;
        std::cout << "一致しました" << std::endl;
    }
    else
    {
        //std::wcout << L"一致しませんでした" << std::endl;
        std::cout << "一致しませんでした" << std::endl;
    }

    // 正常終了
    return( 0 );
}

