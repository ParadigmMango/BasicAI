#include <iostream>

#include <Aliases.h>
#include "MnistLoader.h"
#include "Network.h"
#include "NetworkUtilities.h"

int main() {
    Network net({784, 16, 16, 10});
    
    Images images =
            mnist_loader::ReadImages("Data/Training/train-images-idx3-ubyte");
    Labels labels =
            mnist_loader::ReadLabels("Data/Training/train-labels-idx1-ubyte");

    std::cout << "Loaded training data(" << images.size() << ")\n";

    std::vector<double> out = net.FeedForward(images[0]);

    for (double activation : out)
        std::cout << activation << "\n";

    std::cout << images.size() << ' ' << labels.size();

    std::cout << "End of program.\n";

    return 0;
}
