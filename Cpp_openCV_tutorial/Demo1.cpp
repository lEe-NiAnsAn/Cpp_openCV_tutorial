#include "02_operation.h"

void Demo1::colorSpace_Demo(Mat& image)
{
	Mat gray, hsv;
	//cvtColor(待处理图像对象,指定暂存对象,处理转换方法)
	cvtColor(image, hsv, COLOR_BGR2HSV);	//转换色彩模式由BRG至HSV并暂存至指定对象
	cvtColor(image, gray, COLOR_BGR2GRAY);	//转换灰度由BGR至GRAY并暂存至指定对象
	imshow("HSV", hsv);
	imshow("GRAY", gray);
	//imwrite(保存文件路径/名称,目标对象,图像质量)——>末参数未传为默认参数
	imwrite("hsv.jpg", hsv);	
	imwrite("gray.jpg", gray);	//保存指定对象至指定路径
}