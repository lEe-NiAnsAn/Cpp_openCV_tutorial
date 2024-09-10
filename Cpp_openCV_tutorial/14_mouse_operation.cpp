#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "14_mouse_operation.h"

int main14(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}
	Demo13 d13;
	d13.mouse_drawing_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}