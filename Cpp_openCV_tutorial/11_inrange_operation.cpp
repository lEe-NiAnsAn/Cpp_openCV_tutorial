#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "11_inrange_operation.h"

int main(int argc, char** argv)
{
	Mat src = imread("greenback.png");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}
	imshow("原图像", src);
	Demo10 d10;
	d10.inrange_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}