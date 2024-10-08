#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
#include "24_convolution.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		std::cout << "无法读取到图像……";
		return -1;
	}
	imshow("读取图像", src);
	Demo23 d23;
	d23.blur_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}