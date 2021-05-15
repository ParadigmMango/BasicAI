#ifndef ALIASES_H_
#define ALIASES_H_

#include <array>
#include <vector>

using Biases = std::vector<std::vector<double>>;
using Image = std::array<double, 784>;
using Images = std::vector<Image>;
using Labels = std::vector<double>;
using Weights = std::vector<std::vector<std::vector<double>>>;

#endif // ALIASES_H_