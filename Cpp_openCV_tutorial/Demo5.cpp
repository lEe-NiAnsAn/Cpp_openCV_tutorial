#include "06_tracking_bar.h"

static void on_track_l(int light, void* userdata)	
//其中：(void*)为任意变量指针
{
	Mat dst, mo, image;
	image = *((Mat*)userdata);
	dst = Mat::zeros(image.size(), image.type());
	mo = Mat::zeros(image.size(), image.type());

	if(light > 50)	//变亮
	{
		mo = Scalar((light - 50) * 2, (light - 50) * 2, (light - 50) * 2);
		add(image, mo, dst);
		imshow("调整", dst);
	}
	else	//变暗
	{
		mo = Scalar((50 - light) * 2, (50 - light) * 2, (50 - light) * 2);
		subtract(image, mo, dst);
		imshow("调整", dst);
	}
}
static void on_track_c(int contrast, void* userdata)	
{
	Mat dst, mo, image;
	image = *((Mat*)userdata);
	dst = Mat::zeros(image.size(), image.type());
	mo = Mat::zeros(image.size(), image.type());

	if(contrast >= 50)	//提高对比度
	{
		double p_c = (contrast - 50) / 50.0  + 1.0;
		addWeighted(image, p_c, mo, 0, 0, dst);
		imshow("调整", dst);
	}
	else	//降低对比度
	{
		double n_c = 1.0 - (50 - contrast) / 50.0;
		addWeighted(image, n_c, mo, 0.0, 0, dst);
		imshow("调整", dst);
	}
}
void Demo5::tracking_bar_demo(Mat& image)
{
	namedWindow("调整", WINDOW_AUTOSIZE);
	//调整亮度
	int now_l = 50;	//设置原亮度值
	int max_l = 100;	//设置最大亮度值
	on_track_l(now_l, &image);	//向操作函数传参
	createTrackbar("亮度", "调整", &now_l, max_l, on_track_l, (void*)(&image));
	//创建滑块|参数一：滑块名；参数二：显示窗口；参数三：待更改值；参数四：最大值(最小值0)
	//参数五：操作函数——>固定参数

	//调整对比度
	on_track_l(now_l, &image);
	createTrackbar("对比度", "调整", &now_l, max_l, on_track_c, (void*)(&image));

}
