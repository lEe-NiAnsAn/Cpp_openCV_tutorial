#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
#include "20_video_save.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		std::cout << "无法读取到图像……";
		return -1;
	}
	Demo19 d19;
	d19.videos_demo(src);
	destroyAllWindows();

	return 0;
}