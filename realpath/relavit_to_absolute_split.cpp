#include <limits.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string RelativeToAbsolutePath(const std::string& relative_path);
std::vector<std::string> SplitPath(const std::string& path);

int main(int argc, const char* argv[])
{
    const std::vector<std::string> test {
        std::string("testfile.txt"),
        std::string("./testfile.txt"),
        std::string("../testfile.txt"),
        std::string("../../XXX///./testfile.txt/"),
    };
    
    for (const auto& s : test) {
        std::cout << "relative : " << s << std::endl;
        std::cout << "absolute : " << RelativeToAbsolutePath(s) << std::endl;
    }
}

std::string RelativeToAbsolutePath(const std::string& relative_path)
{
    char buffer[PATH_MAX] {};
    std::string cwd(getcwd(buffer, sizeof(buffer)));
    std::vector<std::string> abusolute = SplitPath(cwd);
    std::vector<std::string> relative = SplitPath(relative_path);
    for (const auto& str : relative) {
        if (str == ".") {
            continue;
        }

        if (str == "..") {
            abusolute.pop_back();
        } else {
            abusolute.push_back(str);
        }
    }
    
    std::string abusolute_path;
    for (const auto& str : abusolute) {
        abusolute_path += "/";
        abusolute_path += str;
    }
    
    return abusolute_path;
}

std::vector<std::string> SplitPath(const std::string& path)
{
    std::vector<std::string> v;
    std::stringstream ss(path);
    std::string str;
    while (std::getline(ss, str, '/')) {
        if (!str.empty()) {
            v.push_back(str);
        }
    }
    
    return v;
}

/*
relative : testfile.txt
absolute : /path/to/absolute/testfile.txt
relative : ./testfile.txt
absolute : /path/to/absolute/testfile.txt
relative : ../testfile.txt
absolute : /path/to//testfile.txt
relative : ../../XXX///./testfile.txt/
absolute : /path/XXX/testfile.txt
*/
