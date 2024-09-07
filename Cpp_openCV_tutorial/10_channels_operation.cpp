#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "10_channels_operation.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}
	Demo9 d09;
	d09.channels_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}