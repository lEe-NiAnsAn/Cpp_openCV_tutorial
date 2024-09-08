#include "14_mouse_operation.h"

Point start_p(-1, -1);
Point end_p(-1, -1);
Mat temp;
static void on_draw(int event, int x, int y, int flag, void* userdata)
{//(鼠标事件,鼠标X轴位置,鼠标Y轴位置,鼠标状态,回调参数)
	Mat dst = *((Mat*)userdata);
	if (event == EVENT_LBUTTONDOWN)	//按下左键
	{
		start_p.x = x;
		start_p.y = y;
	}
	else if (event == EVENT_LBUTTONUP)	//松开左键
	{
		end_p.x = x;
		end_p.y = y;
		int delta_x = end_p.x - start_p.x;
		int delta_y = end_p.y - start_p.y;
		if (delta_x > 0 && delta_y > 0)
		{
			Rect box(start_p.x, start_p.y, delta_x, delta_y);	//创建矩形对象
			imshow("选中区域", temp(box));
			//Mat(Rect)：以Rect中的区域截取Mat中区域创建新图像对象
			rectangle(dst, box, Scalar(0, 0, 200), 1, 8, 0);
			imshow("鼠标绘制", dst);
		}
		start_p.x = -1;
		start_p.y = -1;	//重置坐标
	}
	else if (event == EVENT_MOUSEMOVE)	//鼠标移动
	{
		if (start_p.x > 0 && start_p.y > 0)	//实现重置坐标
		{
			end_p.x = x;
			end_p.y = y;
			int delta_x = end_p.x - start_p.x;
			int delta_y = end_p.y - start_p.y;
			if (delta_x > 0 && delta_y > 0)
			{
				temp.copyTo(dst);
				Rect box(start_p.x, start_p.y, delta_x, delta_y);
				rectangle(dst, box, Scalar(0, 0, 200), 1, 8, 0);
				imshow("鼠标绘制", dst);
			}
		}
	}
}
void Demo13::mouse_drawing_demo(Mat& image)
{
	namedWindow("鼠标绘制", WINDOW_AUTOSIZE);
	//(目标窗口,回调函数,回调参数)
	setMouseCallback("鼠标绘制", on_draw, &image);
	imshow("鼠标绘制", image);
	temp = image.clone();	//image暂存至temp
}
