#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(void)
{
	Mat dst(400, 500, CV_32FC1);
	Mat tmp(dst);
	Mat src = imread("C:/tmp/getpic.jpg");
	resize(src, dst, dst.size());
	resize(src, tmp, tmp.size());

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	cout << element << endl;
	cout << element.size().width << endl;
	cout << element.size().height << endl;
	
	erode(dst, dst, element);

	//imshow("tmp", tmp);
	//imshow("dst", dst);
	//cvtColor(dst, dst, COLOR_BGRA2GRAY);
	//cvtColor(tmp, tmp, COLOR_BGRA2GRAY);

	imshow("dst-tmp", dst-tmp);

	waitKey();
	
	return 1;
}