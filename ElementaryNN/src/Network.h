#ifndef NETWORK_H_
#define NETWORK_H_

#include <vector>

class Network {
  public:
    Network(std::vector<int> sizes);
    ~Network();

  private:
    int num_layers_, num_elements_;
    std::vector<int> sizes_;
    std::vector<std::vector<double>> biases_;
    std::vector<std::vector<std::vector<double>>> weights_;
};

#endif  // NETWORK_H_
