#include "opencv2/opencv.hpp"
#include <iostream>
#include <windows.h>

using namespace std;
using namespace cv;

#define WINDOW_WIDTH	600

void DrawEllipse(Mat src, double angle);
void DrawEllipse(Mat src, double angle, int thickness);
void DrawFilledCircle(Mat src, Point point);
void DrawPolygon(Mat src);
void DrawLine(Mat src, Point start, Point end);


int main(int argc, const char** argv)
{
	Mat src1(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3, Scalar(255, 0, 0));
	double point1 = 0;
	DrawEllipse(src1, point1);
	DrawEllipse(src1, 90, -8);
	imshow("src1", src1);
	cout << src1.size().width << endl;
	//resize(src1, src1,Size(src1.rows*1.5,src1.cols*1.5),CV_INTER_LINEAR);
	//imshow("src11", src1);

	Mat src2(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3, Scalar(255, 0, 0));
	Point point2(WINDOW_WIDTH / 2,WINDOW_WIDTH / 2);
	DrawFilledCircle(src2, point2);
	imshow("src2", src2);

	Mat src3(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3, Scalar(255, 0, 0));
	DrawPolygon(src3);
	
	Point startp(0, 0), endp(WINDOW_WIDTH, WINDOW_WIDTH);
	DrawLine(src3, startp, endp);

	imshow("src3", src3);

	Mat src4(900, 900, CV_8UC3, Scalar(0, 0, 0));
	ellipse(src4, Point(450, 450), Size(400, 250), 0, 0, 360, Scalar(0, 0, 255), 5, 8);
	ellipse(src4, Point(450, 450), Size(250, 110), 90, 0, 360, Scalar(0, 0, 255), 5, 8);
	ellipse(src4, Point(450, 320), Size(280, 120), 0, 0, 360, Scalar(0, 0, 255), 5, 8);
	imshow("src4",src4);


	waitKey(0);

	return true;

}

void DrawEllipse(Mat src, double angle)
{
	int thickness = 5;
	int linetype = 8;
	ellipse(src,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 3),
		angle,
		0,
		270,
		Scalar(255, 192, 0),
		thickness,
		linetype
	);
}

void DrawEllipse(Mat src, double angle,int thickness)
{
	int linetype = 8;
	ellipse(src,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 3),
		angle,
		0,
		270,
		Scalar(255, 192, 0),
		thickness,
		linetype
	);
}

void DrawFilledCircle(Mat src, Point point)
{
	int thickness = -1;
	int lineType = 8;

	circle(src,
		point,
		WINDOW_WIDTH / 4,
		Scalar(0, 0, 255),
		thickness,
		lineType,
		0
	);
}

void DrawPolygon(Mat src)
{
	int lineType = 8;

	//创建一些点
	Point rookPoints[1][20];
	rookPoints[0][0] = Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
	rookPoints[0][1] = Point(3 * WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
	rookPoints[0][2] = Point(3 * WINDOW_WIDTH / 4, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][3] = Point(11 * WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][4] = Point(19 * WINDOW_WIDTH / 32, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][5] = Point(3 * WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][6] = Point(3 * WINDOW_WIDTH / 4, WINDOW_WIDTH / 8);
	rookPoints[0][7] = Point(26 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][8] = Point(26 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][9] = Point(22 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][10] = Point(22 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][11] = Point(18 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][12] = Point(18 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][13] = Point(14 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][14] = Point(14 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][15] = Point(WINDOW_WIDTH / 4, WINDOW_WIDTH / 8);
	rookPoints[0][16] = Point(WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][17] = Point(13 * WINDOW_WIDTH / 32, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][18] = Point(5 * WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][19] = Point(WINDOW_WIDTH / 4, 13 * WINDOW_WIDTH / 16);

	const Point* ppt[1] = { rookPoints[0] };
	int npt[] = { 20 };

	fillPoly(src,
		ppt,
		npt,
		1,
		Scalar(255, 255, 255),
		lineType);
}

void DrawLine(Mat src, Point start, Point end)
{
	int thickness = 5;
	int LineType = 8;

	line(src, start, end, Scalar(0, 255, 0), thickness, LineType);
}