#include "04_pixel_visit.h"

void Demo3::pixel_visit_demo(Mat& image)
{
	int w = image.cols;	//�����(��)
	int h = image.rows;	//�����(��)
	int c = image.channels();	//ͨ����
	//�±����
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (c == 1)	//��ͨ���Ҷ�ͼ��
			{
				int pv = image.at<uchar>(row, col);	//�������ص�,ǿתΪint
				image.at<uchar>(row, col) = 255 - pv;	//�޸����ص�(uchar:0~255)
			}
			if (c == 3)	//��ͨ����ɫͼ��
			{
				Vec3b bgr = image.at<Vec3b>(row, col);	//�������ص�,ʹ��Vec3b����
														//Vec3b:��������,���浥���ص���ͨ������
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];	
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];	
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];	//�޸����ص�(bgr[]:0~255)
			}
		}
	}
	imshow("��ɫͼ��", image);
	imwrite("��ɫ.jpg",image);
	//ָ�����
	for (int row = 0; row < h; row++)
	{
		uchar* current_row = image.ptr<uchar>(row);	//��ȡ��ǰ��ָ��
		for (int col = 0; col < w; col++)
		{	//ѭ���еĳ���
			if (c == 1)
			{
				*current_row++ = 255 - *current_row;	//�����ã��Ӹ������ױ�������β
			}
			if (c == 3)
			{
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;	//�����ã��Ӹ������ױ�����ͨ������β
			}
		}
	}
	imshow("��ԭͼ��", image);
}