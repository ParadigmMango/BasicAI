#include "MnistLoader.h"

namespace mnist_loader {

// Works with image datasets only and parses them into vectors
// 
// Inpired by both:
//   https://stackoverflow.com/a/33384846
//   https://compvisionlab.wordpress.com/2014/01/01/c-code-for-reading-mnist-data-set/
std::vector<std::array<double, 784>> ReadImages(const std::string &full_path) {
    std::ifstream file(full_path, std::ios::binary);

    std::vector<std::array<double, 784>> images;

    if (file.is_open()) {
        int magic_num;
        file.read((char *) &magic_num, sizeof(magic_num));
        magic_num = ReverseInt(magic_num);

        if(magic_num != 2051) throw "Invalid MNIST image file!";

        int img_num;
        file.read((char *) &img_num, sizeof(img_num));
        img_num = ReverseInt(img_num);
        
        images.resize(img_num);

        int num_rows;
        file.read((char *) &num_rows, sizeof(num_rows));
        num_rows = ReverseInt(num_rows);
        
        int num_cols;
        file.read((char *) &num_cols, sizeof(num_cols));
        num_cols = ReverseInt(num_cols);

        const int num_px = num_rows * num_cols;
        
        unsigned char temp;
        for (int i = 0; i < img_num; ++i) {
            for (int p = 0; p < num_px; ++p) {
                file.read((char *) &temp, 1);
                images[i][p] = (double) temp / 255.0;
            }
        }
    }

    return images;
}

// Works with label datasets only and parses them into vectors
// 
// Inpired by both:
//   https://stackoverflow.com/a/33384846
//   https://compvisionlab.wordpress.com/2014/01/01/c-code-for-reading-mnist-data-set/
std::vector<double> ReadLabels(const std::string &full_path) {
    std::ifstream file(full_path, std::ios::binary);

    std::vector<double> labels;

    if (file.is_open()) {
        int magic_num;
        file.read((char *) &magic_num, sizeof(magic_num));
        magic_num = ReverseInt(magic_num);

        if(magic_num != 2049) throw "Invalid MNIST label file!";

        int label_num;
        file.read((char *) &label_num, sizeof(label_num));
        label_num = ReverseInt(label_num);

        labels.resize(label_num);

        unsigned char temp;        
        for (int i = 0; i < label_num; ++i) {
            file.read((char *) &temp, 1);
            labels[i] = (double) temp;
        }
    }

    return labels;
}

// Reverses the order of the bytes of an int
//
// Copy/pasted from this https://stackoverflow.com/a/10409376
int ReverseInt(const int &num) {
    unsigned char c1, c2, c3, c4;

    c1 = num & 255;
    c2 = (num >> 8) & 255;
    c3 = (num >> 16) & 255;
    c4 = (num >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

// Turn a digit n into an array that is all zeroes except the nth element,
// which is 1.0
std::array<double, 10> VectorizedResult(const double &n) {
    std::array<double, 10> result = {0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0};
    
    result[n] = 1.0;

    return result;
}

} // namespace mnist_loader
