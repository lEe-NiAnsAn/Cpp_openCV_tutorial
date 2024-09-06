#include "07_key_operation.h"

void Demo6::key_demo(Mat& image)
{
	Mat dst = Mat::zeros(image.size(), image.type());
	while (true)
	{
		int c = waitKey(10);	//��Ƶ����ʱĬ��Ϊ1	
		if (c == 27) {std::cout << "�˳�\n";break; }	//�˳�esc��
		if (c == 49)	//����1��
		{
			std::cout << "����Ҷ�ͼ��\n";
			cvtColor(image, dst, COLOR_BGR2GRAY);
		}
		if (c == 50)	//����2��
		{
			std::cout << "���ɫ��ģʽHSV\n";
			cvtColor(image, dst, COLOR_BGR2HSV);
		}
		if (c == 51)	//����3��
		{
			std::cout << "�������\n";
			dst = Scalar(100, 100, 100);
			add(image, dst, dst);
		}
		imshow("������Ӧ", dst);
	}
}