#include <iostream>
#include <opencv2/opencv.hpp>
#include <unistd.h>

using namespace std;
using namespace cv;

int add(int a, int b){
    return a+b;
}
int sub(int a,int b,int c){
    return a+b+c;
}
int main() {
    Mat src = imread("/home/zcl/图片/timg.jpeg");
    namedWindow("Hello",CV_WINDOW_AUTOSIZE);    
    imshow("Hello",src);
    waitKey(0);



    return 0;
}
