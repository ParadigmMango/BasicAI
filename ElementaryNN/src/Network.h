#ifndef NETWORK_H_
#define NETWORK_H_

#include <vector>
#include <utility>

#include "Aliases.h"

class Network {
  public:
    Network(const std::vector<int> &sizes);
    std::pair<Biases, Weights> Backprop(const Labels &labels,
            const Images &images);
    std::vector<double> FeedForward(const Image &activations);

  private:
    int num_layers_, num_elements_;
    std::vector<int> sizes_;
    Biases biases_;
    Weights weights_;
};

#endif  // NETWORK_H_
