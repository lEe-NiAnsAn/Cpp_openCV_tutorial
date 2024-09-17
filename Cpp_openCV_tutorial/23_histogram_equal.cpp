#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
#include "23_histogram_equal.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		std::cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}
	imshow("��ȡͼ��", src);
	Demo22 d22;
	d22.hist_eq_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}