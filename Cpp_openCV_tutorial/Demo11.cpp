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
	std::cout<< "ͨ��" << i+1<< "����>��Сֵ��" << minv << " ���ֵ��" << maxv << std::endl;
	}
	Mat mean, studdev;
	meanStdDev(image, mean, studdev);
	std::cout << "ƽ��ֵ��" << mean << "\n��׼���" << studdev << std::endl;
}