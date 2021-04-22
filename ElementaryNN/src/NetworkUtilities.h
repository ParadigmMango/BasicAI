#ifndef NETWORK_UTILITIES_H_
#define NETWORK_UTILITIES_H_

#include <vector>

namespace network_utilities {

std::vector<double> DotProduct(std::vector<std::vector<double>> a,
        std::vector<double> b);

double Sigmoid(double z);

std::vector<double> Sigmoid(std::vector<double> z);

std::vector<double> SumVectors(const std::vector<double> &a,
        const std::vector<double> &b);

} // namespace network_utilities

#endif  // NETWORK_UTILITIES_H_
