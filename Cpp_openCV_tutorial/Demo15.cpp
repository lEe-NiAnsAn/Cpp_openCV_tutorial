#include "16_resize&interp.h"

void Demo15::resize_demo(Mat& image)
{
	Mat zoomin, zoomout;
	int w = image.cols;
	int h = image.rows;
	resize(image, zoomin, Size(w / 2, h / 2), 0.0, 0.0);
	//参数一：源图像；参数二：输出图像；参数三：resize大小；参数四五：缩放比例(默认0.0:原比例)；参数六：插值方式(默认1:线性)
	//缩放比例：当参数三Size为空或0时，将按照fx,fy对水平方向与竖直方向进行缩放
	imshow("缩小图像", zoomin);
	resize(image, zoomout, Size(0,0), 1.5, 1.5);
	imshow("放大图像", zoomout);
}