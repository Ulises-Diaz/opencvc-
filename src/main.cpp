#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("", cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Error: No se pudo cargar la imagen.\n";
        return -1;
    }
    cv::imshow("Imagen", image);
    cv::waitKey(0);
    return 0;
}
