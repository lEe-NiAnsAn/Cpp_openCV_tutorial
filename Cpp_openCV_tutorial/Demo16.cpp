#include "17_flip_operation.h"

void Demo16::flip_demo(Mat& image)
{
	Mat dst;
	flip(image, dst, 0);	//�ߵ�
	imshow("ͼ��ߵ�", dst);
	flip(image, dst, 1);	//����
	imshow("ͼ����", dst);
	flip(image, dst, -1);	//���Ķ�ת
	imshow("ͼ�����Ķ�ת", dst);
}
