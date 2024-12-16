#include <iostream>
#include <opencv2/opencv.hpp>


/*

This code is for Laplace filters. Try them :) !!!!

*/


int main() {
    // Carga de la imagen en escala de grises
    cv::Mat img = cv::imread("/home/uli/Desktop/tec/personal/vision/c++/data/Leo.jpg", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        std::cerr << "Error: Unable to load the image.\n";
        return -1;
    }

    // Crear ventanas con tamaño ajustable
    cv::namedWindow("INPUT", cv::WINDOW_NORMAL);
    cv::namedWindow("OUTPUT", cv::WINDOW_NORMAL);

    // Ajustar el tamaño inicial de las ventanas
    cv::resizeWindow("INPUT", 200, 200);  // Ventana INPUT: 600x400 píxeles
    cv::resizeWindow("OUTPUT", 200, 200); // Ventana OUTPUT: 600x400 píxeles
    cv::resizeWindow("Laplace", 200, 200);

    cv::Mat Img_output, laplace_out;

    // Parámetros de Sobel
    int dx = 1; //True or false
    int dy = 1; //True or false. Cant be both 0 or 1
    //dx focus on horizontal lines, dy on vertical lines
    int sobel_kernel_size = 3;
    int scaleFactor = 2;
    int deltaValue = 2;

    while (1) {
        // Aplicar filtro Sobel
        cv::Sobel(img, Img_output, CV_8UC1, dx, dy, sobel_kernel_size, scaleFactor, deltaValue);

        //Apply Laplace
        cv::Laplacian(img,laplace_out, -1, 1, 1, 0); //(input,output, depth, kernel size, scale factor, delta)

        // Mostrar imágenes en las ventanas
        cv::imshow("INPUT", img);
        cv::imshow("Laplace", laplace_out);
        cv::imshow("OUTPUT", Img_output);

        // Leer teclas presionadas
        int c = cv::waitKey(1);
        if ((char)c == 'q') {
            std::cout << "Pressed 'q'. Exiting.\n";
            break;
        } else if ((char)c == 'a') {
            std::cout << "Pressed 'a'.\n";
           if (dx && dy) {
                dx = 0;
            } 
            else {
                dx = 1;
            } 

        } else if ((char)c == 's') {
            std::cout << "Pressed 's'.\n";
            if (dx && dy) {
                dy = 0;
            } 
            else {
                dy = 1;
            } 
        } else if ((char)c == 'd') {
            std::cout << "Pressed 'd'.\n";
            sobel_kernel_size +=2;
        }
         else if ((char)c == 'f') {
            std::cout << "Pressed 'f'.\n";
            if(sobel_kernel_size >1){
                sobel_kernel_size -=2;
            }
        }
        else if ((char)c == 'z') {
            std::cout << "Pressed 'z'.\n";
            scaleFactor ++;
        }
        else if ((char)c == 'x') {
            std::cout << "Pressed 'x'.\n";
            scaleFactor --;
        }
        else if ((char)c == 'c') {
            std::cout << "Pressed 'c'.\n";
            deltaValue ++;
        }
        else if ((char)c == 'v') {
            std::cout << "Pressed 'v'.\n";
            deltaValue --;
        }
    }


    return 0;
}
