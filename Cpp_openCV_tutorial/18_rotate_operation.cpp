#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
#include "18_rotate_operation.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		std::cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}
	imshow("ԭͼ��", src);
	Demo17 d17;
	d17.rotate_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}