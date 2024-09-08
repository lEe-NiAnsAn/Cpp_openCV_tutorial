#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "13_drawing_object.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}
	Demo12 d12;
	d12.drawing_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}