#include <iostream>
#include <vector>

#include "MnistLoader.h"
#include "Network.h"
#include "NetworkUtilities.h"

int main() {
    Network net({3, 746, 10});

    std::vector<double> out = net.FeedForward({0.3509240542,
                                               0.2799612631,
                                               0.3180355991});

    for (double activation : out)
        std::cout << activation << "\n";
    
    std::vector<double> labels = mnist_loader::ReadLabels("Data/Training/train-labels-idx1-ubyte");

    for (int i = 0; i < 10; ++i)
        std::cout << labels[i] << ' ';

    std::cout << "End of program.\n";

    return 0;
}
