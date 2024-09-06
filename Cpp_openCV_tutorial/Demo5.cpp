#include "06_tracking_bar.h"

static void on_track_l(int light, void* userdata)	
//���У�(void*)Ϊ�������ָ�룬����ʱ��ָ��
{
	Mat dst, mo, image;
	image = *((Mat*)userdata);
	dst = Mat::zeros(image.size(), image.type());
	mo = Mat::zeros(image.size(), image.type());

	if(light > 50)	//����
	{
		mo = Scalar((light - 50) * 2, (light - 50) * 2, (light - 50) * 2);
		add(image, mo, dst);
		imshow("���ȵ���", dst);
	}
	else	//�䰵
	{
		mo = Scalar((50 - light) * 2, (50 - light) * 2, (50 - light) * 2);
		subtract(image, mo, dst);
		imshow("���ȵ���", dst);
	}
}
void Demo5::tracking_bar_demo(Mat& image)
{
	namedWindow("���ȵ���", WINDOW_AUTOSIZE);
	int now_l = 50;	//����ԭ����ֵ
	int max_l = 100;	//�����������ֵ
	on_track_l(now_l, &image);	//�������������
	createTrackbar("����", "���ȵ���", &now_l, max_l, on_track_l,(void*)(&image));
	//��������|����һ��������������������ʾ���ڣ���������������ֵ�������ģ����ֵ(��СֵĬ��0)
	//�����壺������������>�̶��������������������ݴ����ص�����
}
