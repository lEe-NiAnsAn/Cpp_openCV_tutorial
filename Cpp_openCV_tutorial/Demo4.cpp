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
	//�˷�����(����ʵ��)
	//�������������⣬�޷�ֱ��ʹ��*���ؽ���������ͨͼ��
	multiply(image, Scalar(10, 10, 10), dst);	//����
	imshow("�˷�����", dst);

	//��ײ��﷨��
	dst = Mat::zeros(image.size(), image.type());
	Mat mo = Mat::zeros(image.size(),image.type());
	mo = Scalar(80, 80, 80);
	int w = dst.cols;	
	int h = dst.rows;	
	for (int row = 0; row < h; row++)
	{
		uchar* row1 = dst.ptr<uchar>(row);	
		uchar* row2 = mo.ptr<uchar>(row);	
		uchar* row3 = image.ptr<uchar>(row);	
		for (int col = 0; col < w; col++)
		{
			//saturate_cast<uchar>()��ȷ����Խ��ģ���������ȡֵ��Χ����ucharΪ0~255
			*row1++ = saturate_cast<uchar>((*row2++) + (*row3++));
			*row1++ = saturate_cast<uchar>((*row2++) + (*row3++));
			*row1++ = saturate_cast<uchar>((*row2++) + (*row3++));
		}
	}
	imshow("��������ײ�", dst);
	//����ʵ�֣�����
	add(image, mo, dst);
	imshow("������������", dst);
	//����ʵ�֣����
	subtract(image, mo, dst);
	imshow("�����������", dst);
	//����ʵ�֣���ֵ
	divide(image, mo, dst);
	imshow("������ֵ����", dst);
}