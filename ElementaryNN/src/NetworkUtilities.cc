#include "Network.h"

#include <math.h>

namespace network_utilities {

double Sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

} // namespace network_utilities