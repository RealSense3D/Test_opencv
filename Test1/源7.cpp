#include "opencv2/opencv.hpp"

using namespace cv;

void on_MouseHandler(int event, int x, int y, int flags, void*param);
void DrawRectangle(Mat &img, Rect box);
void ShowHelpText(void);

Rect g_rectangle;
bool g_bDrawingBox = false;
RNG g_rng(12345);

int main(int argc, char** argv)
{
	ShowHelpText();

	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tmpImage;
	srcImage.copyTo(tmpImage);
	// tmpImage = srcImage.clone();
	srcImage = Scalar::all(0);

	namedWindow("test");
	setMouseCallback("test", on_MouseHandler, (void*)&srcImage);

	while (1)
	{
		srcImage.copyTo(tmpImage);
		if (g_bDrawingBox)
			DrawRectangle(tmpImage, g_rectangle);
		imshow("test", tmpImage);
		if (27 == waitKey(1))
			break;
	}

	return true;
}

void ShowHelpText(void)
{
	system("color 0F");

	printf("\nhello world!\n");
	//system("cls");
	printf("\nlul\n");

}

void on_MouseHandler(int event, int x, int y, int flags, void* param)
{

	Mat& image = *(cv::Mat*) param;
	switch (event)
	{
		//����ƶ���Ϣ
	case EVENT_MOUSEMOVE:
	{
		if (g_bDrawingBox)//����Ƿ���л��Ƶı�ʶ��Ϊ�棬���¼�³��Ϳ�RECT�ͱ�����
		{
			g_rectangle.width = x - g_rectangle.x;
			g_rectangle.height = y - g_rectangle.y;
		}
	}
	break;

	//���������Ϣ
	case EVENT_LBUTTONDOWN:
	{
		g_bDrawingBox = true;
		g_rectangle = Rect(x, y, 0, 0);//��¼��ʼ��
	}
	break;

	//���̧����Ϣ
	case EVENT_LBUTTONUP:
	{
		g_bDrawingBox = false;//�ñ�ʶ��Ϊfalse
							  //�Կ�͸�С��0�Ĵ���
		if (g_rectangle.width < 0)
		{
			g_rectangle.x += g_rectangle.width;
			g_rectangle.width *= -1;
		}

		if (g_rectangle.height < 0)
		{
			g_rectangle.y += g_rectangle.height;
			g_rectangle.height *= -1;
		}
		//���ú������л���
		DrawRectangle(image, g_rectangle);
	}
	break;

	}
}

void DrawRectangle(Mat &img, Rect box)
{
	rectangle(img, box.tl(), box.br(),
		Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));
}