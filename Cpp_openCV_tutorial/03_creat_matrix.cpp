//Mat数据由header头部与DataBlock数据部分组成
//header存储Mat内数据的类型与特性等，并指向对应DataBlock
//赋值时仅创建新header指向同一DataBlock，克隆时才完全拷贝DataBlock
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "03_creat_matrix.h"

int main03(int argc, char** argv)
{
	Mat src = imread("test01.png");
	if (src.empty())
	{
		cout << "无法读取到图像……";
		return -1;
	}

	Demo2 d02;
	d02.mat_creation_demo(src);	//调用成员方法克隆、创建、打印输出图像对象

	imshow("输入图像", src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}