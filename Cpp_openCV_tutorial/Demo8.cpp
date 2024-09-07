#include "09_logic_operation.h"

void Demo8::bitwise_demo(Mat& image)
{
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	//(���ƶ���,�������С,��ɫ,�߿�,����ģʽ,���꾫��)
	rectangle(m1, Rect(0, 0, 166, 166), Scalar(240, 190, 145), -1, LINE_8, 0);
	//Rect(���Ͻ�x����,���Ͻ�y����,���ο�,���θ�)
	//�߿�С��0��ֱ����䣬����0��Ϊ���Ʊ߿�����ؿ��
	//����ģʽ�����ڿ���ݵ��������Ʒ�ʽ
	//���꾫��shift��0�򲻽������ţ����������갴��2��shift�η��������ƣ�ͼ��ߴ罫�ȱ���С
	rectangle(m2, Rect(90, 90, 150, 150), Scalar(217, 212, 245), 16, LINE_AA, 0);

	Mat dst;
	//����������������240(11110000) & 217(11011001) = 208(11010000)
	bitwise_and(m1, m2, dst);
	imshow("�����", dst);	//��ͼ�����Ӧͨ�������ƽ��������
	bitwise_or(m1, m2, dst);
	imshow("�����", dst);	//��ͼ�����Ӧͨ�������ƽ��л����
	bitwise_xor(m1, m2, dst);
	imshow("������", dst);	//��ͼ�����Ӧͨ�������ƽ���������
	bitwise_not(image, dst);
	imshow("�ǲ���", dst);	//��ͨ�����ж����Ʒǲ���
}