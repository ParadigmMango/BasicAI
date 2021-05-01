#ifndef MNIST_LOADER_H_
#define MNIST_LOADER_H_

#include <array>
#include <string>
#include <vector>

namespace mnist_loader {

std::vector<std::array<double, 28>> ReadImages(const std::string &path);

std::vector<double> ReadLabels(const std::string &path);

int ReverseInt(const int &num);

std::vector<double> VectorizedResult(double j);

} // namespace mnist_loader

#endif // MNIST_LOADER_H_