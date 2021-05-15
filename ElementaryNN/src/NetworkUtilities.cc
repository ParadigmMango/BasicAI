#include "NetworkUtilities.h"

#include <math.h>

namespace network_utilities {

// Precondition: a is non-jagged and a[0] is the same length as b
std::vector<double> DotProduct(const std::vector<std::vector<double>> &a,
        const std::vector<double> &b) {
    std::vector<double> product;
    int sum;

    for (int i = 0; i < a.size(); ++i) {
        sum = 0;
        for (int j = 0; j < a[0].size(); ++j)
            sum += a[i][j] * b[j];

        product.push_back(sum);   
    }

    return product;
}

double Sigmoid(const double &z) {
    return 1.0 / (1.0 + exp(-z));
}

std::vector<double> Sigmoid(const std::vector<double> &z) {
    std::vector<double> out;
    out.resize(z.size());

    for (int i = 0; i < z.size(); ++i)
        out[i] = Sigmoid(z[i]);
    
    return out;
}

double SigmoidPrime(const double &z) {
    return Sigmoid(z) / (1.0 - Sigmoid(z));
}

std::vector<double> SigmoidPrime(const std::vector<double> &z) {
    std::vector<double> out;
    out.resize(z.size());

    for (int i = 0; i < z.size(); ++i)
        out[i] = SigmoidPrime(z[i]);
    
    return out;
}

// Precondition: a is the same length as b
std::vector<double> SumVectors(const std::vector<double> &a,
        const std::vector<double> &b) {
    std::vector<double> sum;

    for (int i = 0; i < a.size(); ++i)
        sum.push_back(a[i] + b[i]);
    
    return sum;
}

} // namespace network_utilities
