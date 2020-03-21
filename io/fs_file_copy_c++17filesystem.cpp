//#include <filesystem>
// https://cpplover.blogspot.com/2017/01/gccfilesystem.html
#include <experimental/filesystem>
#include <fstream>
#include <iostream>

// g++-7 -std=c++17 -o fs_file_copy fs_file_copy.cpp -lstdc++fs

namespace fs = std::experimental::filesystem;

int main(int argc, char* argv[]) {
    fs::path from_path("file_a");
    std::ofstream file(from_path);
    file.close();

    fs::path to_path("file_b");

    fs::copy_file(from_path, to_path);

    std::cout << std::boolalpha << fs::exists(to_path) << std::endl;

    return 0;
}
