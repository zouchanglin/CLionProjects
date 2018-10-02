#include <iostream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
    for(int i = 0;i<10;i++){
        cout<<i<<endl;
    }
    Mat src = imread("C:\\Users\\Tim\\Pictures\\a.png");
    namedWindow("src",CV_WINDOW_AUTOSIZE);
    imshow("src",src);
    cout<<"hello"<<endl;    

    waitKey(0);
    return 0;

}
