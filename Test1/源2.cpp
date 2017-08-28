#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void main()
{
	Mat src = imread("C:/tmp/getpic.jpg");
	Mat tmp, dst;

	//Mat kk(20,20,)

	cvtColor(src, tmp, COLOR_BGRA2GRAY);
//	Canny(tmp, tmp, 30, 100);
	blur(src, tmp, Size(5, 5));
	//blur(src, dst, Size(20, 20));//ÖÐÖµÂË²¨
	//filter2D(tmp,dst,30,)

	imshow("tmp", tmp);
	imshow("dst", dst);

	waitKey();

}