#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
#include "16_resize&interp.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		std::cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}
	imshow("ԭͼ��", src);
	Demo15 d15;
	d15.resize_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}