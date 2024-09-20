#include "23_histogram_equal.h"

void Demo22:: hist_eq_demo(Mat& image)
{
	Mat gray;
	//直方图均衡化仅支持单通道图像
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("原灰度图像", gray);
	Mat dst;
	equalizeHist(gray, dst);
	//直方图均衡化使得图像对比度加强，在一定程度上可增强图像效果
	//原理：通过算法将原图统计过后直方图的灰度区间进行重新分配，使得各灰度区间均衡化
	imshow("直方图均衡化", dst);
}