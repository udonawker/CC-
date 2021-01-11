int main(int argc, char* argv[])
{
    auto read_file = []( const std::string& path ){
        std::ifstream f(path);
        std::stringstream ss;
        ss << f.rdbuf();
        return ss.str();
    };
    
    std::string str = read_file("test.txt");
    return 0;
}
