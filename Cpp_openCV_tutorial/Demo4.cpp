#include "05_arithmetic_operation.h"

void Demo4::operators_demo(Mat& image)
{
	//��������
	Mat dst;
	dst = image + Scalar(180, 180, 180);	//����
	imshow("���Ӳ���", dst);
	//�������
	dst = image - Scalar(180, 180, 180);	//�䰵
	imshow("�������", dst);
	//��ֵ����
	dst = image / Scalar(10, 10, 10);	//�䰵
	imshow("��ֵ����", dst);
	//�˷�����
	//�������������⣬�޷�ֱ��ʹ��*���ؽ�������
	multiply(image, Scalar(10, 10, 10), dst);	//����
	imshow("�˷�����", dst);
}