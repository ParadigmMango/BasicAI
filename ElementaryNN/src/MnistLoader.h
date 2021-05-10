#ifndef MNIST_LOADER_H_
#define MNIST_LOADER_H_

#include <array>
#include <fstream>
#include <string>
#include <vector>

namespace mnist_loader {

std::vector<std::array<double, 784>> ReadImages(const std::string &full_path);

std::vector<double> ReadLabels(const std::string &full_path);

int ReverseInt(const int &num);

std::array<double, 10> VectorizedResult(double j);

} // namespace mnist_loader

#endif // MNIST_LOADER_H_
