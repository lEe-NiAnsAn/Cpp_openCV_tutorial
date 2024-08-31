#include <iostream>
#include <opencv2/opencv.hpp>
#include "02_operation.h"
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("test01.png");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}
	
	Demo1 d01;
	d01.colorSpace_Demo(src);	//调用成员方法转换色彩空间

	imshow("输入图像", src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}