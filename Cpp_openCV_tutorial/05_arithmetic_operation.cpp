#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "05_arithmetic_operation.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}
	imshow("显示图像", src);
	Demo4 d04;
	d04.operators_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}