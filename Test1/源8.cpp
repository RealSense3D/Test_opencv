#include "opencv2/opencv.hpp"
#include <iostream>
#include <windows.h>

using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
	Mat src = imread("C:/tmp/getpic.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);

	Mat M;
	////M.create(2, 2, CV_8UC3);

	M = (Mat_<double>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);

	cout << "M\n" << M << ";" << endl << endl;

	Mat N0 = M.row(0).clone();
	Mat N1 = M.row(1).clone();
	Mat N2 = M.row(2).clone();
	cout << "N0\n" << N0 << ";" << endl << endl;
	cout << "N1\n" << N1 << ";" << endl << endl;
	cout << "N2\n" << N2<< ";" << endl << endl;

	//cout << "FMT_C\n"		<< format(M, Formatter::FMT_C)		 << endl << endl;
	//cout << "FMT_CSV\n"		<< format(M, Formatter::FMT_CSV)	 << endl << endl;
	//cout << "FMT_DEFAULT\n" << format(M, Formatter::FMT_DEFAULT) << endl << endl;
	//cout << "FMT_MATLAB\n"	<< format(M, Formatter::FMT_MATLAB)	 << endl << endl;
	//cout << "FMT_NUMPY\n"	<< format(M, Formatter::FMT_NUMPY)   << endl << endl;
	//cout << "FMT_PYTHON\n"	<< format(M, Formatter::FMT_PYTHON)	 << endl << endl;
	//imshow("hello", M);

	//vector<float> a;
	//a.push_back(3);
	//a.push_back(4);
	//a.push_back(5);
	//a.pop_back();
	//a.swap(a);
	////a.x = 1;
	////a.y = 4;
	//cout << Mat(a) << endl;
	Mat a = src(Rect(50, 200, 200, 200));
	Mat b = src(Rect(250, 200, 200, 200));
	imshow("1", a);
	imshow("2", b);
	cout << "a.dims\t" << a.dims << endl;
	cout << "a.rows\t" << a.rows << endl;
	cout << "a.cols\t" << a.cols << endl;
	cout << "a.size\t" << a.size() << endl;
	cout << "a.channels\t" << a.channels() << endl;
	Size s(200, 200);
	Mat aa(400, 600, CV_8UC3,Scalar(0,0,255));
	Mat bb;
	bb.create(aa.size(), aa.depth());
	cout << "bb.size\t" << bb.size() << endl;
	cout << "aa.size\t" << aa.size() << endl;
	imshow("aa", aa);

	Mat t1 = aa(Rect(150, 150, 200, 200));
	t1 = a;
	cvtColor(t1, t1, COLOR_BGR2Lab);
	imshow("aa2", t1);

	waitKey(0);
/*
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
		{
			cout << a.at<int>(i, j);
			dst.at<float>(i, j) = a.at<float>(i, j);
		}
	}	
	for (int i = 0; i < b.rows; i++)
	{
		for (int j = 0; j < b.cols; j++)
		{
			dst.at<float>(i+a.rows, j+a.cols) = b.at<float>(i, j);
		}
	}
	imshow("gg", dst);*/

	//getchar();
	//Sleep(10000);


	return true;
}