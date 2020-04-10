#include <iostream>
#include <fstream>
#include <vector>
#include <random>

// g++ -std=c++11 -o diffgen diffgen.cpp

static int generateDiff(
    const std::vector<std::uint8_t>&    input,
    std::vector<std::uint8_t>&          output
)
{
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());
    std::uniform_int_distribution<> dist1(1, 4);
    std::bernoulli_distribution dist3(0.2);

    for (int i = 0; i < (int)input.size(); i++) {
        int shiftBit = dist3(engine) ? dist1(engine) : 0;
        output[i] = input[i] >> shiftBit;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cout << argv[0] << " <input file> <output file> " << std::endl;
        return -1;
    }

    std::ifstream infile(argv[1], std::ios::in | std::ios::binary);
    std::ofstream outfile(argv[2], std::ios::out | std::ios::binary);
    infile.seekg(0, std::ios::end);
    auto fileSize = infile.tellg();
    infile.seekg(0, std::ios::beg);

    std::vector<std::uint8_t> input(fileSize);
    std::vector<std::uint8_t> output(fileSize);

    infile.read(reinterpret_cast<std::ios::char_type*>(&input[0]), fileSize);

    generateDiff(input, output);

    outfile.write(reinterpret_cast<std::ios::char_type*>(&output[0]), fileSize);

    return 0;
}

