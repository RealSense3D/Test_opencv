//#include <iostream>
//using std::cout;
//using std::endl;
//using std::fixed;
//using std::scientific;
//
//int main()
//{
//	double x = 0.001234567;
//	double y = 1.946e9;
//
//	cout << "Displayed in default format:" << endl << x << '\t' << y << endl;
//
//	cout << "\nDisplayed in scientific format:" << endl << scientific << x << '\t' << y << endl;
//
//	cout << "\nDisplayed in fixed format:" << endl << fixed << x << '\t' << y << endl;
//
//	getchar();
//	return 0;
//}

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	printf("\nOpenCV version is  " CV_VERSION);
	printf("\nOpenCV version major is %.3f", (float)CV_VERSION_MAJOR);
	printf("\nOpenCV version minor is %d", CV_VERSION_MINOR);
	printf("\nOpenCV version revision is %d", CV_VERSION_REVISION);
	printf("\nOpenCV version status is %s", CV_VERSION_STATUS);

	Mat src = imread("C:/tmp/getpic.jpg",CV_LOAD_IMAGE_ANYDEPTH|CV_LOAD_IMAGE_ANYCOLOR);

	printf("\ncols is %d,rows is %d\n", src.cols, src.rows);
	Mat tmp,dst;

	if (!src.empty())
	{
		printf("\nno empty!");
	}
	else
	{
		printf("\nempty.");
		return false;
	}

	cvtColor(src,tmp,COLOR_BGR2GRAY);
	int r1 = 50;
	int r2 = 50;

	int c1 = 30;
	int c2 = 100;
	Mat edges;
	namedWindow("Tab");

	while (true)
	{

		createTrackbar("T1", "Tab", &c1, 255, 0);
		createTrackbar("T2", "Tab", &c2, 255, 0);
		Canny(tmp, edges, c1, c2);

		//namedWindow("ss");
		//imshow("ss", edges);

		Mat rotR0 = src(Range(50, 250), Range(225, 425));
		Mat rotR1 = src(Rect(425, 50, 200, 200));

		//src = edges;

		//printf("\n%d\t%d",rotR0.size().width,rotR0.size().height);
		//printf("\n%d\t%d",rotR1.cols,rotR1.rows);

		//imshow("r1", rotR0);
		//imshow("r2", rotR1);

		createTrackbar("R1(%)", "Tab", &r1, 100, 0);
		createTrackbar("R2(%)", "Tab", &r2, 100, 0);
		double r11 = (double)r1/100;
		double r22 = (double)r2/100;
		addWeighted(rotR0, r11, rotR1, r22, 0, dst);

		//imshow("dst", dst);

		//int  a = getTrackbarPos("R1(%)", "Tab");
		//printf("\n%d\n", a);

		Mat M1(200, 200, CV_8UC1, Scalar(0, 0, 255));
		//imshow("M1", M1);
		//cout << "\n\nM1\n" << M1 << endl;

		Mat M2(2, 2, CV_8UC2, Scalar(0, 0, 255));
		//cout << "\n\nM2\n" << M2 << endl;

		Mat M3(200, 200, CV_8UC3, Scalar(0, 0, 255));
		//imshow("M3", M3);
		//cout << "\n\nM3\n" << M3 << endl;

		Mat M4(2, 3, CV_8UC4, Scalar(0, 0, 255));
		//imshow("M4", M4);
		cout << "m41"<<M4(Range(1,2),Range(2,2))<< endl;
		cout << "m42"<<M4 << endl;
		//cout << "\n\nM4\n" << M4 << endl;

		//int sz[2]={ 2,2};
		//Mat L(3, sz, CV_8UC3, Scalar::all(0));
		//cout << L << endl;

		if (27 == waitKey(1))break;
		
	}
	
	return 1;
}