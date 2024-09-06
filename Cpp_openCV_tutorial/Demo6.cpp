#include "07_key_operation.h"

void Demo6::key_demo(Mat& image)
{
	Mat dst = Mat::zeros(image.size(), image.type());
	while (true)
	{
		int c = waitKey(10);	//视频分析时默认为1	
		if (c == 27) {std::cout << "退出\n";break; }	//退出esc键
		if (c == 49)	//数字1键
		{
			std::cout << "变更灰度图像\n";
			cvtColor(image, dst, COLOR_BGR2GRAY);
		}
		if (c == 50)	//数字2键
		{
			std::cout << "变更色彩模式HSV\n";
			cvtColor(image, dst, COLOR_BGR2HSV);
		}
		if (c == 51)	//数字3键
		{
			std::cout << "提高亮度\n";
			dst = Scalar(100, 100, 100);
			add(image, dst, dst);
		}
		imshow("键盘响应", dst);
	}
}