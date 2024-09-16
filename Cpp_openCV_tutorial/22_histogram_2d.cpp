#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
#include "22_histogram_2d.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		std::cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}
	imshow("��ȡͼ��", src);
	Demo21 d21;
	d21.histogram2d_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}