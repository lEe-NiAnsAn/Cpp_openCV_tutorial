#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
#include "23_histogram_equal.h"

int main23(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		std::cout << "无法读取到图像……";
		return -1;
	}
	imshow("读取图像", src);
	Demo22 d22;
	d22.hist_eq_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}