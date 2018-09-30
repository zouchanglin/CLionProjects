#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
int add(int a, int b){

    return a+b;
}
int main(int argc, char const *argv[])
{
    Mat src = imread("/home/zcl/图片/timg.jpeg");
    int ret =  add(2,9);
    for(int i = 0;i<10;i++){
        std::cout << i+1 << std::endl;
    }
    std::cout<<ret<<std::endl;
    namedWindow("src",CV_WINDOW_AUTOSIZE);
    imshow("src", src);
    waitKey(0);
    return 0;
}


