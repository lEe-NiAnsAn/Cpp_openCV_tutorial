#include "18_rotate_operation.h"

void Demo17::rotate_demo(Mat& image)
{
	Mat dst, M;	//MΪ�������任��2*3��������
	int w = image.cols;
	int h = image.rows;
	M = getRotationMatrix2D(Point2f(w / 2, h / 2), 45.0, 1.0);	//��ȡ��ת��������
	double cos = abs(M.at<double>(0, 0));
	double sin = abs(M.at<double>(0, 1));
	int new_w = cos * w + sin * h;
	int new_h = sin * w + cos * h;	//������ת��ͼ���С
	M.at<double>(0, 2) += (new_w / 2 - w / 2);
	M.at<double>(1, 2) += (new_h / 2 - h / 2);	//������ת��������
	//����һ����ת�������ꣻ����������ת�Ƕ�(��ʱ��)����������������С
	warpAffine(image,dst,M,Size(new_w,new_h),INTER_LINEAR, 0,Scalar(0, 255, 0));
	//����һ��Դͼ�񣻲����������ͼ�񣻲���������������
	//�����ģ���ֵ��(Ĭ��:1���Բ�ֵ)�������壺�߽����ģʽ(Ĭ��:0�������)�������������߽�Ϊ������䣬����趨�����ɫ(Ĭ��:����)
	imshow("��תͼ��", dst);
}