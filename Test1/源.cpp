//打开摄像头样例
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

#define uint unsigned int

int main()
{
	char key = 0;
	Mat src;
	uint counter = 0;

	// VideoCapture cap(0);
	while (1)
	{
		//cap >> src;
		
		src = imread("C:/tmp/getpic.jpg");
		if (src.empty())
		{
			printf("error-2");
			return -2;
		}

		
		 cout<<Scalar(0, 0, 255)<<endl;

		//imshow("show", src);
		getchar();
		return -1;

		if (src.empty())
		{
			cout << "can not open camera" << endl;
			return -1;
		}

		Mat dst, cdst;
		Canny(src, dst, 50, 200, 3);
		cvtColor(dst, cdst, COLOR_GRAY2BGR);
		cdst = src;

#if 0
		vector<Vec2f> lines;
		HoughLines(dst, lines, 1, CV_PI / 180, 100, 0, 0);

		for (size_t i = 0; i < lines.size(); i++)
		{
			float rho = lines[i][0], theta = lines[i][1];
			Point pt1, pt2;
			double a = cos(theta), b = sin(theta);
			double x0 = a*rho, y0 = b*rho;
			pt1.x = cvRound(x0 + 1000 * (-b));
			pt1.y = cvRound(y0 + 1000 * (a));
			pt2.x = cvRound(x0 - 1000 * (-b));
			pt2.y = cvRound(y0 - 1000 * (a));
			line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);
		}
#else
		vector<Vec4i> lines;
		HoughLinesP(dst, lines, 1, CV_PI / 180, 50, 50, 10);
		for (size_t i = 0; i < lines.size(); i++)
		{
			Vec4i l = lines[i];
			line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
		}
#endif
		//imshow("source", src);
		imshow("detected lines", cdst);


		printf("%d\t", counter);
		counter++;
		key = waitKey(1);
		if (key == 27)
		{
			break;
		}
	}
	return 0;
}