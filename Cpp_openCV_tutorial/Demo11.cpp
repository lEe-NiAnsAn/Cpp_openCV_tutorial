#include "12_pixel_statistics.h"

void Demo11::pixel_statistics_demo(Mat& image)
{
	double minv, maxv;
	Point minLoc, maxLoc;
	std::vector<Mat> mv;
	split(image, mv);
	for (int i = 0; i < image.channels(); i++)
	{//(统计图像,最小位指针,最大位指针,最小位坐标指针,最大位坐标指针,掩码对象)
	minMaxLoc(mv[i], &minv, &maxv, &minLoc, &maxLoc);
	//掩码对象：默认为空，将统计所有位；非空将统计图像位于掩码中非0位置的像素点
	std::cout<< "通道" << i+1<< "——>最小值：" << minv << " 最大值：" << maxv << std::endl;
	std::cout << "\t最小位坐标：(" << minLoc.x << "," << minLoc.y
			  << ") \t最大位坐标：(" << maxLoc.x << "," << maxLoc.y << ")\n\n";
	}
	Scalar mean, studdev;
	//(统计图像,平均值矩阵,标准方差矩阵)
	meanStdDev(image, mean, studdev);
	for (int i = 0; i < image.channels(); i++)
	{
		std::cout << "\n通道" << i + 1
			<< "——>平均值：" << mean[i] << " 标准方差：" << studdev[i];
	}
}