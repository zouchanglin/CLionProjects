#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

    Mat ret = imread("/home/zcl/VSworkspace/Image/a.jpg");
    namedWindow("TestOpencv",CV_WINDOW_AUTOSIZE);
    imshow("TestOpencv",ret);

    waitKey(0);
    return 0;
}