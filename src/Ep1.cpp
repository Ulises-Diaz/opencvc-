#include <iostream>
#include <opencv2/opencv.hpp>

// This is a tutorial to open a image 

int main(){

    //to read an image
    cv::Mat img = cv::imread(
        "", //add directory to ur image
        cv::IMREAD_COLOR); //it adds a filter. cv::IMREAD has lots of options

    //to show the image
    cv::imshow("Window" , img); //Window title is Window

    //To delay and mantain the image
    cv::waitKey(0);

    return 0;
}