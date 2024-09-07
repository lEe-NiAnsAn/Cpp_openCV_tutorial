#include "11_inrange_operation.h"

void Demo10::inrange_demo(Mat& image)
{
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);	//HSV色彩空间的基本色区分度较RBG更高，便于提取
	Mat mask;
	//对图像进行二值化处理，将区间内的像素点所有位均置1(白色)，区间外均置0(黑色)
	//(源图像,消除下限,消除上限,输出图像)
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);
	//基本色中对应的HSV分量来源于网络，绿色即为上述示例
	imshow("去绿幕蒙版", mask);

	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(0, 0, 200);
	redback.copyTo(image, mask);	//拷贝redback在mask蒙版下所有位均不为0的区域至image
	imshow("红底图像", image);									       //(即白色区域)
}