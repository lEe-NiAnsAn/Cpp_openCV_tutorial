#include "15_conver&norm.h"

void Demo14::norm_demo(Mat& image)
{
	Mat dst;
	image.convertTo(image, CV_32F);	//将图像由字节型转换为(rbg三通道的)32位浮点型
	//参数一：输出图像；参数二：目标格式；参数三：缩放倍数(默认1.0)；参数四：加权量(默认0.0)
	normalize(image, dst, 1.0, 0, NORM_MINMAX);	//归一化处理
	//参数一：源图像；参数二：输出图像；参数三：归一化上界(默认1.0)；参数四：下界(默认0.0)；
	//参数五：归一化类型(默认4:NORM_L2欧几里得范数归一)
	//参数六：输出深度(默认-1:同源图像)；参数七：掩码
	imshow("直接转为浮点型图像", image);
	imshow("归一化处理", dst);
	//uchar取值为0~255，直接转为 float不变
	//正确显示浮点型的图像需要使矩阵中的数值位于0~1间，故需归一化处理
}