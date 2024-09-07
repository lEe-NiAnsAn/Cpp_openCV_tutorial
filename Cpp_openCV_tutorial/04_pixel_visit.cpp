#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "04_pixel_visit.h"

int main04(int argc, char** argv)
{
	Mat src = imread("test01.png");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}
	imshow("原图像", src);
	Demo3 d03;
	d03.pixel_visit_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}