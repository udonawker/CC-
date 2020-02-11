#include <istream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[])
{
    std::iostream ios(std::fstream());
    ios = std::move(dynamic_cast<std::iostream>(std::stringstream()));
}
