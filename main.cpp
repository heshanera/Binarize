/* 
 * File:   main.cpp
 * Author: heshan
 *
 * Created on March 3, 2018, 10:05 PM
 */

#include <iostream>

#include "opencv2/imgproc.hpp"
#include <opencv2/highgui.hpp>

double thresh;
double maxValue; 

cv::Mat globalThreshold(cv::Mat img) {
    cv::Mat output;
    // Set threshold and maxValue
    thresh = 50;
    maxValue = 255; 
    // Binary Threshold
    threshold(img, output, thresh, maxValue, cv::THRESH_BINARY);
    return output;
}

cv::Mat adaptiveMeanThreshold(cv::Mat img) {
    cv::Mat output;
    // Set threshold and maxValue
    maxValue = 255; 
    // Adaptive Threshold
    adaptiveThreshold(img, output, maxValue, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY,11,2);
    return output;
}

cv::Mat adaptiveGaussianThreshold(cv::Mat img) {
    cv::Mat output;
    // Set threshold and maxValue
    maxValue = 255; 
    // Adaptive Threshold
    adaptiveThreshold(img, output, maxValue, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY,11,2);
    return output;
}

cv::Mat otsuThreshold(cv::Mat img) {
    cv::Mat output;
    // Set threshold and maxValue
    thresh = 50;
    maxValue = 255; 
    // Otsu Threshold
    threshold(img, output, thresh, maxValue, cv::THRESH_BINARY + cv::THRESH_OTSU);
    return output;
}

int main() {

    cv::Mat input = cv::imread("imgs/input.jpg", 0);
    cv::Mat output;
  
    output = globalThreshold(input);
    cv::imwrite( "imgs/globalThresholdOut.jpg", output );

    output = adaptiveMeanThreshold(input);
    cv::imwrite( "imgs/adaptiveMeanThresholdOut.jpg", output );
    
    output = adaptiveGaussianThreshold(input);
    cv::imwrite( "imgs/adaptiveGaussianThresholdOut.jpg", output );
    
    output = otsuThreshold(input);
    cv::imwrite( "imgs/otsuThresholdOut.jpg", output );
    
    return 0;
}
