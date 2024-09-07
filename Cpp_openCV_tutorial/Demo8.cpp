#include "09_logic_operation.h"

void Demo8::bitwise_demo(Mat& image)
{
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	//(绘制对象,坐标与大小,颜色,线宽,线条模式,坐标精度)
	rectangle(m1, Rect(0, 0, 166, 166), Scalar(240, 190, 145), -1, LINE_8, 0);
	//Rect(左上角x坐标,左上角y坐标,矩形宽,矩形高)
	//线宽：小于0则直接填充，大于0则为绘制边框的像素宽度
	//线条模式：关于抗锯齿的线条绘制方式
	//坐标精度shift：0则不进行缩放，非零则坐标按照2的shift次方进行右移，图像尺寸将等比缩小
	rectangle(m2, Rect(90, 90, 150, 150), Scalar(217, 212, 245), 16, LINE_AA, 0);

	Mat dst;
	//例如二进制与操作：240(11110000) & 217(11011001) = 208(11010000)
	bitwise_and(m1, m2, dst);
	imshow("与操作", dst);	//两图像各对应通道二进制进行与操作
	bitwise_or(m1, m2, dst);
	imshow("或操作", dst);	//两图像各对应通道二进制进行或操作
	bitwise_xor(m1, m2, dst);
	imshow("异或操作", dst);	//两图像各对应通道二进制进行异或操作
	bitwise_not(image, dst);
	imshow("非操作", dst);	//各通道进行二进制非操作
}