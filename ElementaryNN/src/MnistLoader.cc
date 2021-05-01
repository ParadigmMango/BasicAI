#include "MnistLoader.h"

namespace mnist_loader {

// std::vector<std::array<double, 784>> ReadImages(const std::string &path);

// std::vector<double> ReadLabels(const std::string &path);

// Reverses the order of the bytes of an int
//
// Copy/pasted from this https://stackoverflow.com/a/10409376
int ReverseInt(const int &num) {
    unsigned char c1, c2, c3, c4;

    c1 = num & 255;
    c2 = (num >> 8) & 255;
    c3 = (num >> 16) & 255;
    c4 = (num >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

// Turn a digit n into an array that is all zeroes except the nth element,
// which is 1.0
std::array<double, 10> VectorizedResult(double n) {
    std::array<double, 10> result = {0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0};
    
    result[n] = 1.0;

    return result;
}

} // namespace mnist_loader
