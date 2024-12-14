#include <iostream>
#include <opencv2/opencv.hpp>

/*this is a tutorial for Erosion and dilation images

1. Erosion: Makes wider the edges

2. Dilation: Makes thinner the edges

*/

int main(){

    //to read an image
    cv::Mat img = cv::imread(
        "",//add the direcoty of your image
        cv::IMREAD_COLOR); //it adds a filter. cv::IMREAD has lots of options
    
    
    //Declate variables
    cv::Mat erodeMat,dilateMat;
    cv::Mat elementKernel;
    //also works : cv::Mat elementKernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15,15), cv::point(-1,-1)1)
    
    //Use filter
    
    //Erode
    cv::erode(img, erodeMat, elementKernel, cv::Point(-1, -1), 3); //last number modifies edges

    //Dilation
    cv::dilate(img,dilateMat, elementKernel, cv::Point(-1,-1),1); //point is to start from the middle
    
    //Show images
    cv::imshow("Erosde Image", erodeMat);
    cv::imshow("Dilate image", dilateMat);
    cv::imshow("Original Image", img);
    
    //To delay and mantain the image
    cv::waitKey(0);

    return 0;
}
