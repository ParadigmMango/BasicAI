#include <iostream>

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
    
    std::vector<std::array<double, 784>> images =
            mnist_loader::ReadImages("Data/Training/train-images-idx3-ubyte");
    std::vector<double> labels =
            mnist_loader::ReadLabels("Data/Training/train-labels-idx1-ubyte");

    std::cout << images.size() << ' ' << labels.size();

    std::cout << "End of program.\n";

    return 0;
}
