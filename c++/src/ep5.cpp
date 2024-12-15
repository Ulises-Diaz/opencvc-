#include <iostream>
#include <opencv2/opencv.hpp>


/*

This code is for Convolution. cv::filter2d()

*/

int main() {
    // Crear una matriz personalizada de 3x3 con valores float
    cv::Mat custom= cv::imread ("/home/uli/Desktop/tec/personal/vision/c++/data/Leo.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat_<float>kernel(3,3);

    //This kernel is to sharpen images
    kernel<<-1,1,-1,
           1,1,1,
           -1,1,-1 ; //u can change this. If the sum gives you 1, the output is normal. Try when it gives u 0.


    // Crear una ventana para mostrar la matriz
    cv::namedWindow("Custom", cv::WINDOW_NORMAL);
    cv::namedWindow("Kernel", cv::WINDOW_NORMAL);
    cv::namedWindow("Gaussian", cv::WINDOW_NORMAL);

    // Escalar los valores de la matriz para visualización (0-255)
    cv::Mat custom2, kernel2, filter2d, filter2d2, gauss, gauss2;

    //Guassian
    cv::GaussianBlur(custom, gauss, cv::Size(3,3),0);

    //filtro
    cv::filter2D(custom,filter2d, -1, kernel, cv::Point(-1,-1));

    custom.convertTo(custom2, CV_8UC1);
    kernel.convertTo(kernel2, CV_8UC1);
    filter2d.convertTo(filter2d2, CV_8UC1);
    gauss.convertTo(gauss2, CV_8UC1);

    
    // Mostrar la matriz escalada como imagen
    cv::imshow("Custom", custom2);
    cv::imshow("Kernel", kernel2);
    cv::imshow("Filter2D", filter2d2);

    // Esperar a que el usuario presione una tecla
    cv::waitKey(0);

    return 0;
}
