#include "16_resize&interp.h"

void Demo15::resize_demo(Mat& image)
{
	Mat zoomin, zoomout;
	int w = image.cols;
	int h = image.rows;
	resize(image, zoomin, Size(w / 2, h / 2), 0.0, 0.0);
	//����һ��Դͼ�񣻲����������ͼ�񣻲�������resize��С���������壺���ű���(Ĭ��0.0:ԭ����)������������ֵ��ʽ(Ĭ��1:����)
	//���ű�������������SizeΪ�ջ�0ʱ��������fx,fy��ˮƽ��������ֱ�����������
	imshow("��Сͼ��", zoomin);
	resize(image, zoomout, Size(0,0), 1.5, 1.5);
	imshow("�Ŵ�ͼ��", zoomout);
}