#include "06_tracking_bar.h"

static void on_track_l(int light, void* userdata)	
//其中：(void*)为任意变量指针，传入时需指定
{
	Mat dst, mo, image;
	image = *((Mat*)userdata);
	dst = Mat::zeros(image.size(), image.type());
	mo = Mat::zeros(image.size(), image.type());

	if(light > 50)	//变亮
	{
		mo = Scalar((light - 50) * 2, (light - 50) * 2, (light - 50) * 2);
		add(image, mo, dst);
		imshow("亮度调整", dst);
	}
	else	//变暗
	{
		mo = Scalar((50 - light) * 2, (50 - light) * 2, (50 - light) * 2);
		subtract(image, mo, dst);
		imshow("亮度调整", dst);
	}
}
void Demo5::tracking_bar_demo(Mat& image)
{
	namedWindow("亮度调整", WINDOW_AUTOSIZE);
	int now_l = 50;	//设置原亮度值
	int max_l = 100;	//设置最大亮度值
	on_track_l(now_l, &image);	//向操作函数传参
	createTrackbar("亮度", "亮度调整", &now_l, max_l, on_track_l,(void*)(&image));
	//创建滑块|参数一：滑块名；参数二：显示窗口；参数三：待更改值；参数四：最大值(最小值默认0)
	//参数五：操作函数——>固定参数；参数六：将数据传至回调函数
}
