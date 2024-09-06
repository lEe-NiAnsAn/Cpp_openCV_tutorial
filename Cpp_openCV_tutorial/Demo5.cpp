#include "06_tracking_bar.h"

static void on_track_l(int light, void* userdata)	
//���У�(void*)Ϊ�������ָ��
{
	Mat dst, mo, image;
	image = *((Mat*)userdata);
	dst = Mat::zeros(image.size(), image.type());
	mo = Mat::zeros(image.size(), image.type());

	if(light > 50)	//����
	{
		mo = Scalar((light - 50) * 2, (light - 50) * 2, (light - 50) * 2);
		add(image, mo, dst);
		imshow("����", dst);
	}
	else	//�䰵
	{
		mo = Scalar((50 - light) * 2, (50 - light) * 2, (50 - light) * 2);
		subtract(image, mo, dst);
		imshow("����", dst);
	}
}
static void on_track_c(int contrast, void* userdata)	
{
	Mat dst, mo, image;
	image = *((Mat*)userdata);
	dst = Mat::zeros(image.size(), image.type());
	mo = Mat::zeros(image.size(), image.type());

	if(contrast >= 50)	//��߶Աȶ�
	{
		double p_c = (contrast - 50) / 50.0  + 1.0;
		addWeighted(image, p_c, mo, 0, 0, dst);
		imshow("����", dst);
	}
	else	//���ͶԱȶ�
	{
		double n_c = 1.0 - (50 - contrast) / 50.0;
		addWeighted(image, n_c, mo, 0.0, 0, dst);
		imshow("����", dst);
	}
}
void Demo5::tracking_bar_demo(Mat& image)
{
	namedWindow("����", WINDOW_AUTOSIZE);
	//��������
	int now_l = 50;	//����ԭ����ֵ
	int max_l = 100;	//�����������ֵ
	on_track_l(now_l, &image);	//�������������
	createTrackbar("����", "����", &now_l, max_l, on_track_l, (void*)(&image));
	//��������|����һ��������������������ʾ���ڣ���������������ֵ�������ģ����ֵ(��Сֵ0)
	//�����壺������������>�̶�����

	//�����Աȶ�
	on_track_l(now_l, &image);
	createTrackbar("�Աȶ�", "����", &now_l, max_l, on_track_c, (void*)(&image));

}
