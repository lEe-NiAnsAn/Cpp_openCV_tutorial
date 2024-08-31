#include "02_operation.h"

void Demo1::colorSpace_Demo(Mat& image)
{
	Mat gray, hsv;
	//cvtColor(������ͼ�����,ָ���ݴ����,����ת������)
	cvtColor(image, hsv, COLOR_BGR2HSV);	//ת��ɫ��ģʽ��BRG��HSV���ݴ���ָ������
	cvtColor(image, gray, COLOR_BGR2GRAY);	//ת���Ҷ���BGR��GRAY���ݴ���ָ������
	imshow("HSV", hsv);
	imshow("GRAY", gray);
	//imwrite(�����ļ�·��/����,Ŀ�����,ͼ������)����>ĩ����δ��ΪĬ�ϲ���
	imwrite("hsv.jpg", hsv);	
	imwrite("gray.jpg", gray);	//����ָ��������ָ��·��
}