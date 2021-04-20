#include "Network.h"

#include <iostream>
#include <random>

Network::Network(std::vector<int> sizes) {
    // Temporary Rand Initialization - TODO: Find better solution
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0,1.0);

    num_layers_ = sizes.size();

    sizes_ = sizes;

    for (int i = 1; i < num_layers_; ++i) {
        biases_.push_back({});
        for (int j = 0; j < sizes[i]; ++j)
            biases_[i-1].push_back(distribution(generator));
    }        
    
    for (int i = 0; i < num_layers_ - 1; ++i) {
        weights_.push_back({});
        for (int j = 0; j < sizes_[i]; ++j) {
            weights_[i].push_back({});
            for (int k = 0; k < sizes_[i+1]; ++k)
                weights_[i][j].push_back(distribution(generator));
        }
    }            
    
    num_elements_ = 0;
    for (std::vector<double> bias_layer : biases_)
        for (double bias : bias_layer)
            ++num_elements_;
    for (std::vector<std::vector<double>> weight_matrix : weights_)
        for (std::vector<double> weight_layer : weight_matrix)
            for (double weight : weight_layer)
                ++num_elements_;

    std::cout << "num_layers_:\t" << num_layers_
            << "\nnum_elements_:\t" << num_elements_ << "\n";
}

Network::~Network() {}
