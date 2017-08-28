#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 400

void ShowHelpText(void);
void DrawEllipse(Mat src, double point);
void DrawFilledCircle(Mat src, Point point);

int main(int argc, const char **argv)
{
	// 创建空白的Mat图像
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

	ShowHelpText();
	// ---------------------<1>绘制化学中的原子示例图------------------------

	//【1.1】先绘制出椭圆
	DrawEllipse(atomImage, 90);
	DrawEllipse(atomImage, 0);
	DrawEllipse(atomImage, 45);
	DrawEllipse(atomImage, -45);

	imshow("atomimage", atomImage);
	//【1.2】再绘制圆心
	DrawFilledCircle(atomImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
	imshow("atomimage2", atomImage);

	waitKey(0);
	return true;
}

void ShowHelpText(void)
{
	cout << "\nNow we'll draw some ellipses and circles" << endl;
	cout << "\n===============================================\n"
		<< endl;
}

void DrawEllipse(Mat src, double point)
{
	int thickness = 2;
	int lineType = 8;

	ellipse(src,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),
		point,
		0,
		360,
		Scalar(255, 129, 0),
		thickness,
		lineType);
}

void DrawFilledCircle(Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;

	circle(img,
		center,
		WINDOW_WIDTH / 32,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}
