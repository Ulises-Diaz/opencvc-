#include <iostream>
#include <opencv2/opencv.hpp>

//this is a tutorial for filters 
//bilateral filters and common blurs.



int main(){

    //to read an image
    cv::Mat img = cv::imread(
        "/home/uli/Desktop/tec/personal/vision/src/IneAnverso.jpg",
        cv::IMREAD_COLOR); //it adds a filter. cv::IMREAD has lots of options
    
    //filter applications

    //Bilateral filters
    cv:: Mat bilateralImg;
    cv::bilateralFilter(img, bilateralImg,15, 110, 45); //adds colorfull blur. U can change the parameters

    //Gaussian Blur and median Blur
    cv:: Mat gausblurImg, medianblurImg;
    //Gaus. (inputimage, output image, size, extrafilter)
    cv::GaussianBlur(img, gausblurImg, cv::Size(15,15),0);
    //Median
    cv::medianBlur(img,medianblurImg, 15);
    //Median Blur

    //to show the image
    cv::imshow("BilateralImage" , bilateralImg); //Window title is Window
    cv::imshow("Gaussblur", gausblurImg);
    cv::imshow("Median Blur", medianblurImg);
    cv::imshow("Original Image", img);
    //To delay and mantain the image
    cv::waitKey(0);

    return 0;
}