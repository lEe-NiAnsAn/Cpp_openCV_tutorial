#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
#include "19_view_video.h"

int main19(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		std::cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}
	imshow("����ͼ��", src);
	Demo18 d18;
	d18.video_demo(src);
	destroyAllWindows();

	return 0;
}