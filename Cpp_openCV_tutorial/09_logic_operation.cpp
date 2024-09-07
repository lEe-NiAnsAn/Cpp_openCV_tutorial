#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "09_logic_operation.h"

int main(int argc, char** argv)
{
	Mat src = imread("OIP-C.jpg");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}
	Demo8 d08;
	d08.bitwise_demo(src);
	waitKey(0);
	destroyAllWindows();

	return 0;

}