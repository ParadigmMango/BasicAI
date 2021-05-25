#include <iostream>
#include <utility>

#include "Aliases.h"
#include "MnistLoader.h"
#include "Network.h"
#include "NetworkUtilities.h"

int main() {
    Network net({784, 16, 16, 10});
    
    Images images = mnist_loader::ReadImages(
            "Data/Training/train-images-idx3-ubyte");
    VectorizedLabels vectorized_labels = mnist_loader::VectorizeLabels(
            mnist_loader::ReadLabels("Data/Training/train-labels-idx1-ubyte"));

    std::cout << "Loaded training data(" << images.size() << ")\n";

    std::vector<double> out = net.FeedForward(images[0]);
    
    for (const double &activation : out)
        std::cout << activation << "\n";

    std::cout << "End of program.\n";

    return 0;
}
