#include "Network.h"

#include <iostream>
#include <random>

#include "NetworkUtilities.h"

Network::Network(const std::vector<int> &sizes) {
    // Temporary Rand Initialization - TODO: Find better solution
    std::srand(time(NULL));
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<double> dist_rand(0.0,1.0);

    num_layers_ = sizes.size();

    sizes_ = sizes;

    for (int i = 1; i < num_layers_; ++i) {
        biases_.push_back({});
        for (int j = 0; j < sizes[i]; ++j)
            biases_[i-1].push_back(dist_rand(gen));
    }        
    
    for (int i = 0; i < num_layers_ - 1; ++i) {
        weights_.push_back({});
        for (int j = 0; j < sizes_[i+1]; ++j) { // Backwards to 
                                                // simplify FeedForward
            weights_[i].push_back({});
            for (int k = 0; k < sizes_[i]; ++k)
                weights_[i][j].push_back(dist_rand(gen));
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

std::vector<double> Network::FeedForward(std::vector<double> activations) {
    for (int i = 0; i < weights_.size(); ++i)
        activations = network_utilities::Sigmoid(network_utilities::SumVectors(
                network_utilities::DotProduct(weights_[i], activations),
                biases_[i]));
    
    return activations;
}
