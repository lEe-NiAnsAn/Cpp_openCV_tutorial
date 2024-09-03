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
	//乘法运算(方法实现)
	//因数据类型问题，无法直接使用*重载进行运算普通图像
	multiply(image, Scalar(10, 10, 10), dst);	//变亮
	imshow("乘法运算", dst);

	//类底层语法：
	dst = Mat::zeros(image.size(), image.type());
	Mat mo = Mat::zeros(image.size(),image.type());
	mo = Scalar(80, 80, 80);
	int w = dst.cols;	
	int h = dst.rows;	
	for (int row = 0; row < h; row++)
	{
		uchar* row1 = dst.ptr<uchar>(row);	
		uchar* row2 = mo.ptr<uchar>(row);	
		uchar* row3 = image.ptr<uchar>(row);	
		for (int col = 0; col < w; col++)
		{
			//saturate_cast<uchar>()：确保不越界模板参数类型取值范围，对uchar为0~255
			*row1++ = saturate_cast<uchar>((*row2++) + (*row3++));
			*row1++ = saturate_cast<uchar>((*row2++) + (*row3++));
			*row1++ = saturate_cast<uchar>((*row2++) + (*row3++));
		}
	}
	imshow("叠加运算底层", dst);
	//方法实现：叠加
	add(image, mo, dst);
	imshow("方法叠加运算", dst);
	//方法实现：相减
	subtract(image, mo, dst);
	imshow("方法相减运算", dst);
	//方法实现：比值
	divide(image, mo, dst);
	imshow("方法比值运算", dst);
}