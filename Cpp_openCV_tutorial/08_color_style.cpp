#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "08_color_style.h"

int main08(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}
	Demo7 d07;
	d07.color_style_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;

}