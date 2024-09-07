#include "11_inrange_operation.h"

void Demo10::inrange_demo(Mat& image)
{
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);	//HSVɫ�ʿռ�Ļ���ɫ���ֶȽ�RBG���ߣ�������ȡ
	Mat mask;
	//��ͼ����ж�ֵ�������������ڵ����ص�����λ����1(��ɫ)�����������0(��ɫ)
	//(Դͼ��,��������,��������,���ͼ��)
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);
	//����ɫ�ж�Ӧ��HSV������Դ�����磬��ɫ��Ϊ����ʾ��
	imshow("ȥ��Ļ�ɰ�", mask);

	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(0, 0, 200);
	redback.copyTo(image, mask);	//����redback��mask�ɰ�������λ����Ϊ0��������image
	imshow("���ͼ��", image);									       //(����ɫ����)
}