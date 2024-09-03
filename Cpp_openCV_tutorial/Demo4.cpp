#include "05_arithmetic_operation.h"

void Demo4::operators_demo(Mat& image)
{
	//叠加运算
	Mat dst;
	dst = image + Scalar(180, 180, 180);	//变亮
	imshow("叠加操作", dst);
	//相减运算
	dst = image - Scalar(180, 180, 180);	//变暗
	imshow("相减操作", dst);
	//比值运算
	dst = image / Scalar(10, 10, 10);	//变暗
	imshow("比值运算", dst);
	//乘法运算
	//因数据类型问题，无法直接使用*重载进行运算
	multiply(image, Scalar(10, 10, 10), dst);	//变亮
	imshow("乘法运算", dst);
}