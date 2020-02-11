#include <limits.h>
#include <stdlib.h>
#include <string>

// g++ -std=c++11 -o realpath_test realpath_test.cpp
int main(int argc, const char* argv[])
{
    char buffer[PATH_MAX] {};

    const char* relativePath = "./realpath_test.cpp";
    ::printf("Relative = %s\n", relativePath);

    ::printf("ResolvedPath = %s\n", realpath(relativePath, buffer));
}
