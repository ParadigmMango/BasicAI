#include "Network.h"

#include <iostream>
#include <random>

Network::Network(std::vector<int> sizes) {
    // Temporary Rand Initialization - TODO: Find better solution
    std::default_random_engine eng;
    std::normal_distribution<double> dist_rand(0.0,1.0);

    num_layers_ = sizes.size();

    sizes_ = sizes;

    for (int i = 1; i < num_layers_; ++i) {
        biases_.push_back({});
        for (int j = 0; j < sizes[i]; ++j)
            biases_[i-1].push_back(dist_rand(eng));
    }        
    
    for (int i = 0; i < num_layers_ - 1; ++i) {
        weights_.push_back({});
        for (int j = 0; j < sizes_[i+1]; ++j) { // Backwards to simplify sigmoid function
            weights_[i].push_back({});
            for (int k = 0; k < sizes_[i]; ++k)
                weights_[i][j].push_back(dist_rand(eng));
        }
    }            
    
    num_elements_ = 0;
    for (std::vector<double> bias_layer : biases_)
        num_elements_ += bias_layer.size();
    for (std::vector<std::vector<double>> weight_matrix : weights_)
        for (std::vector<double> weight_layer : weight_matrix)
            num_elements_ += weight_layer.size();

    std::cout << num_layers_ << " layer NN(" << num_elements_ << ") created.\n";
}
