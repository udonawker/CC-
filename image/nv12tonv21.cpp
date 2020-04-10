#include <iostream>
#include <fstream>
#include <vector>

// g++ -std=c++11 -o nv12tonv21 nv12tonv21.cpp

static int convertYv12ToNv21(
    const std::vector<std::uint8_t>&    input,
    std::vector<std::uint8_t>&          output,
    int                                 width,
    int                                 height
)
{
    int size = width * height;
    int quarter = size / 4;
    int vPosition = size; // This is where V starts
    int uPosition = size + quarter; // This is where U starts

    std::copy(input.begin(), input.begin() + size, output.begin()); // Y is same

    for (int i = 0; i < quarter; i++) {
        output[size + i * 2] = input[vPosition + i]; // For NV21, V first
        output[size + i * 2 + 1] = input[uPosition + i]; // For Nv21, U second
    }
    return 0;
}

static int convertNv12ToNv21(
    const std::vector<std::uint8_t>&    input,
    std::vector<std::uint8_t>&          output,
    int                                 width,
    int                                 height
)
{
    int size = width * height;

    std::copy(input.begin(), input.begin() + size, output.begin()); // Y is same

    for (int i = 0; i < size / 4; i++) {
        output[size + i * 2]     = input[size + i * 2 + 1]; // For Nv21, V first
        output[size + i * 2 + 1] = input[size + i * 2];     // For Nv21, U second
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 5) {
        std::cout << argv[0] << " <width> <height> <input file> <output file> " << std::endl;
        return -1;
    }

    int width = std::stoi(std::string(argv[1]));
    int height = std::stoi(std::string(argv[2]));
    std::ifstream infile(argv[3], std::ios::in | std::ios::binary);
    std::ofstream outfile(argv[4], std::ios::out | std::ios::binary);
    infile.seekg(0, std::ios::end);
    auto fileSize = infile.tellg();
    infile.seekg(0, std::ios::beg);

    std::vector<std::uint8_t> input(fileSize);
    std::vector<std::uint8_t> output(fileSize);

    infile.read(reinterpret_cast<std::ios::char_type*>(&input[0]), fileSize);

    convertNv12ToNv21(input, output, width, height);

    outfile.write(reinterpret_cast<std::ios::char_type*>(&output[0]), fileSize);

    return 0;
}

