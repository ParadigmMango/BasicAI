#ifndef NETWORK_UTILITIES_H_
#define NETWORK_UTILITIES_H_

#include <vector>

namespace network_utilities {

std::vector<double> DotProduct(const std::vector<std::vector<double>> &a,
        const std::vector<double> &b);

double Sigmoid(const double &z);

std::vector<double> Sigmoid(const std::vector<double> &z);

double SigmoidPrime(const double &z);

std::vector<double> SigmoidPrime(const std::vector<double> &z);

std::vector<double> SumVectors(const std::vector<double> &a,
        const std::vector<double> &b);

} // namespace network_utilities

#endif  // NETWORK_UTILITIES_H_
