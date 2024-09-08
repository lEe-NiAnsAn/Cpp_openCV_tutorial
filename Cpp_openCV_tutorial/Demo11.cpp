#include "12_pixel_statistics.h"

void Demo11::pixel_statistics_demo(Mat& image)
{
	double minv, maxv;
	Point minLoc, maxLoc;
	std::vector<Mat> mv;
	split(image, mv);
	for (int i = 0; i < image.channels(); i++)
	{//(ͳ��ͼ��,��Сλָ��,���λָ��,��Сλ����ָ��,���λ����ָ��,�������)
	minMaxLoc(mv[i], &minv, &maxv, &minLoc, &maxLoc);
	//�������Ĭ��Ϊ�գ���ͳ������λ���ǿս�ͳ��ͼ��λ�������з�0λ�õ����ص�
	std::cout<< "ͨ��" << i+1<< "����>��Сֵ��" << minv << " ���ֵ��" << maxv << std::endl;
	std::cout << "\t��Сλ���꣺(" << minLoc.x << "," << minLoc.y
			  << ") \t���λ���꣺(" << maxLoc.x << "," << maxLoc.y << ")\n\n";
	}
	Scalar mean, studdev;
	//(ͳ��ͼ��,ƽ��ֵ����,��׼�������)
	meanStdDev(image, mean, studdev);
	for (int i = 0; i < image.channels(); i++)
	{
		std::cout << "\nͨ��" << i + 1
			<< "����>ƽ��ֵ��" << mean[i] << " ��׼���" << studdev[i];
	}
}