#include "04_pixel_visit.h"

void Demo3::pixel_visit_demo(Mat& image)
{
	int w = image.cols;	//矩阵宽(列)
	int h = image.rows;	//矩阵高(行)
	int c = image.channels();	//通道数
	//下标访问
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (c == 1)	//单通道灰度图像
			{
				int pv = image.at<uchar>(row, col);	//遍历像素点,强转为int
				image.at<uchar>(row, col) = 255 - pv;	//修改像素点(uchar:0~255)
			}
			if (c == 3)	//三通道彩色图像
			{
				Vec3b bgr = image.at<Vec3b>(row, col);	//遍历像素点,使用Vec3b储存
														//Vec3b:类似数组,储存单像素点三通道数据
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];	
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];	
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];	//修改像素点(bgr[]:0~255)
			}
		}
	}
	imshow("反色图像", image);
	imwrite("反色.jpg",image);
	//指针访问
	for (int row = 0; row < h; row++)
	{
		uchar* current_row = image.ptr<uchar>(row);	//获取当前行指针
		for (int col = 0; col < w; col++)
		{	//循环列的长度
			if (c == 1)
			{
				*current_row++ = 255 - *current_row;	//解引用，从该列行首遍历至行尾
			}
			if (c == 3)
			{
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;	//解引用，从该列行首遍历三通道至行尾
			}
		}
	}
	imshow("还原图像", image);
}