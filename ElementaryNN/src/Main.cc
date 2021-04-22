#include <iostream>
#include <vector>

#include "Network.h"
#include "NetworkUtilities.h"

int main() {
    Network net({3, 746, 10});

    std::vector<double> out = net.FeedForward({0.3509240542,
                                               0.2799612631,
                                               0.3180355991});

    for (double activation : out)
        std::cout << activation << "\n";

    std::cout << "End of program.\n";

    return 0;
}
