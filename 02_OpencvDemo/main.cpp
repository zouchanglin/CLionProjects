#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

    Mat ret = imread("/home/zcl/图片/timg.jpeg");
    namedWindow("ayst", CV_WINDOW_AUTOSIZE);
    imshow("ayst",ret);

    waitKey(0);
    return 0;
}