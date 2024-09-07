#include "12_pixel_statistics.h"

void Demo11::pixel_statistics_demo(Mat& image)
{
	double minv, maxv;
	Point minLoc, maxLoc;
	std::vector<Mat> mv;
	split(image, mv);
	for (int i = 0; i < mv.size(); i++)
	{
	minMaxLoc(mv[i], &minv, &maxv, &minLoc, &maxLoc, Mat());
	std::cout<< "通道" << i+1<< "——>最小值：" << minv << " 最大值：" << maxv << std::endl;
	}
	Mat mean, studdev;
	meanStdDev(image, mean, studdev);
	std::cout << "平均值：" << mean << "\n标准方差：" << studdev << std::endl;
}