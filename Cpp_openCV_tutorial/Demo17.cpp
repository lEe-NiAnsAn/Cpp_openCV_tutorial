#include "18_rotate_operation.h"

void Demo17::rotate_demo(Mat& image)
{
	Mat dst, M;	//M为矩阵仿射变换的2*3参数矩阵
	int w = image.cols;
	int h = image.rows;
	M = getRotationMatrix2D(Point2f(w / 2, h / 2), 45.0, 1.0);	//获取旋转参数矩阵
	double cos = abs(M.at<double>(0, 0));
	double sin = abs(M.at<double>(0, 1));
	int new_w = cos * w + sin * h;
	int new_h = sin * w + cos * h;	//计算旋转后图像大小
	M.at<double>(0, 2) += (new_w / 2 - w / 2);
	M.at<double>(1, 2) += (new_h / 2 - h / 2);	//更新旋转中心坐标
	//参数一：旋转中心坐标；参数二：旋转角度(逆时针)；参数三：放缩大小
	warpAffine(image,dst,M,Size(new_w,new_h),INTER_LINEAR, 0,Scalar(0, 255, 0));
	//参数一：源图像；参数二：输出图像；参数三：参数矩阵；
	//参数四：插值法(默认:1线性插值)；参数五：边界填充模式(默认:0常数填充)；参数六：若边界为常数填充，则可设定填充颜色(默认:纯黑)
	imshow("旋转图像", dst);
}