#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(void)
{
	Mat src = imread("C:/tmp/getpic.jpg");
	imshow("src", src);
	Mat tmp, dst;

	tmp = src.clone();
	cvtColor(tmp, tmp, COLOR_BGRA2GRAY);
	blur(tmp, tmp, Size(3, 3));
	Canny(tmp, tmp, 50, 100);
	imshow("tmp", tmp);

	//morphologyEx(src,dst,)

	Canny(tmp, dst, 50, 100);
	imshow("dst", dst);

	waitKey();

	return true;
}