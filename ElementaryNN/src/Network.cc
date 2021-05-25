#include "Network.h"

#include <iostream>
#include <random>

#include "NetworkUtilities.h"

Network::Network(const std::vector<int> &sizes) {
    // Temporary Rand Initialization - TODO: Find better solution
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
    for (const std::vector<double> &bias_layer : biases_)
        num_elements_ += bias_layer.size();
    for (const std::vector<std::vector<double>> &weight_matrix : weights_)
        for (const std::vector<double> &weight_layer : weight_matrix)
            num_elements_ += weight_layer.size();

    std::cout << num_layers_ << " layer NN(" << num_elements_ << ") created.\n";
}

std::pair<Biases, Weights> Network::Backprop(const Image &image, 
        const VectorizedLabel &label) {
    // Initialize the gradients in the same shape as their respective variables,
    // the copied values are irrelevant.
    Biases bias_gradient = biases_;
    Weights weight_gradient = weights_;

    // Store activations from the feedforward layer by layer in activations_mat
    // and z_mat. z_mat stores the pre-sigmoid values of activations_mat.
    std::vector<double> activations(image.begin(), image.end());
    std::vector<std::vector<double>> activations_mat = {activations};
    std::vector<std::vector<double>> z_mat;
    std::vector<double> z;
    for (int i = 0; i < weights_.size(); ++i) {
        z = network_utilities::SumVectors(network_utilities::DotProduct(
                weights_[i], activations), biases_[i]);
        z_mat.push_back(z);
        activations = network_utilities::Sigmoid(z);
        activations_mat.push_back(activations);
    }

    // Backward pass setup
    std::vector<double> delta = CostDerivative(activations_mat.back(), label);
    std::vector<double> sig_prime =
            network_utilities::SigmoidPrime(z_mat.back());
    for (int i = 0; i < delta.size(); ++i)
        delta[i] *= sig_prime[i];
    bias_gradient.back() = delta;
    weight_gradient.back() = network_utilities::DotProduct(delta,
            activations_mat[activations_mat.size()-2]);

    // Backward pass iteration
    for (int i = sizes_.size()-2; i > 0; --i) {
        z = z_mat[i];
        sig_prime = network_utilities::SigmoidPrime(z);
        delta = network_utilities::DotProduct(
                network_utilities::Transpose(weights_[i]), delta);
        for (int i = 0; i < delta.size(); ++i)
            delta[i] *= sig_prime[i];
        bias_gradient[i-1] = delta;
        weight_gradient[i-1] = network_utilities::DotProduct(delta,
                activations_mat[i-1]);
    }

    // Debuging: prints the shapes of the elements and their gradients
    // for (int i = 0; i < 3; ++i) {
    //     std::cout << biases_[i].size() << '\n';
    //     std::cout << bias_gradient[i].size() << '\n';
    //     std::cout << weights_[i].size() << ' ' <<
    //             weights_[i][0].size() << '\n';
    //     std::cout << weight_gradient[i].size() << ' ' <<
    //             weight_gradient[i][0].size() << '\n';
    // }
    
    return make_pair(bias_gradient, weight_gradient);
}

std::vector<double> Network::CostDerivative(const std::vector<double>
        &output_activations, const VectorizedLabel &label) {
    std::vector<double> new_output_activations = output_activations;

    for (int i = 0; i < 10; ++i)
        new_output_activations[i] = output_activations[i] - label[i];
    
    return new_output_activations;
}

std::vector<double> Network::FeedForward(const Image &activations) {
    std::vector<double> activations_vector(activations.begin(),
            activations.end());

    for (int i = 0; i < weights_.size(); ++i)
        activations_vector = network_utilities::Sigmoid(
                network_utilities::SumVectors(network_utilities::DotProduct(
                weights_[i], activations_vector), biases_[i]));
    
    return activations_vector;
}
