#ifndef MNIST_LOADER_H_
#define MNIST_LOADER_H_

#include <array>
#include <fstream>
#include <string>

#include "Aliases.h"

namespace mnist_loader {

Images ReadImages(const std::string &full_path);

Labels ReadLabels(const std::string &full_path);

int ReverseInt(const int &num);

VectorizedLabels VectorizeLabels(const Labels &labels);

std::array<double, 10> VectorizedResult(const double &n);

} // namespace mnist_loader

#endif // MNIST_LOADER_H_
