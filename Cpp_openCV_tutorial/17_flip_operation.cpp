#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
#include "17_flip_operation.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		std::cout << "无法读取到图像……";
		return -1;
	}
	imshow("原图像", src);
	Demo16 d16;
	d16.flip_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}