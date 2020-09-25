#include "stdafx.h"
#include <opencv/cxcore.h>
#include <opencv2\core\mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

RNG rngee(12345);

int main() {
    Mat im = imread("/home/ashishbisoi/Downloads/counting_stars.png", CV_LOAD_IMAGE_COLOR);
    Mat imgrey = im.clone();
    cvtColor(im, imgrey, CV_RGB2GRAY);
    vector<vector<Point> > imContours;
    vector<Vec4i> hierarchy;

    double divMaxSize = 0.175, divMinSize = 0.125;

   namedWindow("Image", CV_WINDOW_NORMAL| CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED);

   threshold(imgrey, imgrey, 100, 255, 0);

   findContours(imgrey, imContours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    for (int i=0; i < imContours.size(); i++) {
         Scalar color = Scalar( rngee.uniform(0, 255), rngee.uniform(0,255), rngee.uniform(0,255) );
         cout << "sqrt(Area)/arcLength = " << sqrt(contourArea(imContours[i]))/arcLength(imContours[i], true ) << endl;
         if(sqrt(contourArea(imContours[i]))/arcLength(imContours[i], true ) < divMaxSize && sqrt(contourArea(imContours[i]))/arcLength( imContours[i], true ) > divMinSize) 
         {
             drawContours(im, imContours, i, color, 2, 8, hierarchy, 0, Point() ); 
             cout << "I'm a star!" << endl;
         }
        imshow("Image", im);
        waitKey(0);
    }
    imshow("Image", im);
    waitKey(0);

}
