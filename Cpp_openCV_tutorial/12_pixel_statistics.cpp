#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "12_pixel_statistics.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}
	imshow("ͳ��ͼ��", src);
	Demo11 d11;
	d11.pixel_statistics_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}