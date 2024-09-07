#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "06_tracking_bar.h"

int main06(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}
	Demo5 d05;
	d05.tracking_bar_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}