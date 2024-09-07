#include "10_channels_operation.h"

void Demo9::channels_demo(Mat& image)
{
	std::vector<Mat> mv;	//ͨ��Mat��vector�������д洢
	split(image, mv);
	imshow("Bͨ���Ҷ�", mv[0]);
	imshow("Gͨ���Ҷ�", mv[1]);
	imshow("Rͨ���Ҷ�", mv[2]);

	Mat dst;
	std::vector<Mat> temp1;
	split(image, temp1);
	temp1[1] = 0; temp1[2] = 0;
	merge(temp1, dst);	//�ÿ�������ͨ�����кϳ�
	imshow("��ɫͨ��", dst);
	std::vector<Mat> temp2;
	split(image, temp2);
	temp2[0] = 0; temp2[2] = 0;
	merge(temp2, dst);	
	imshow("��ɫͨ��", dst);
	std::vector<Mat> temp3;
	split(image, temp3);
	temp3[1] = 0; temp3[0] = 0;
	merge(temp3, dst);	
	imshow("��ɫͨ��", dst);

	int from_to[] =
	{	0,1,
		1,2,
		2,0,
		3,5,
		4,3,
		5,4	};	//�����ɶԽ���
	//0~2Ϊdst1/ǰimage��ͨ����3~5Ϊdst2/��image��ͨ��
	Mat dst1, dst2;
	dst1 = Mat::zeros(image.size(), image.type());
	dst2 = Mat::zeros(image.size(), image.type());
	Mat image_m[] = { image,image };
	Mat dst_m[] = { dst1,dst2 };
	//(Դͼ������,ͼ������,Ŀ��ͼ����������,ͼ������,ӳ�������,ӳ�������)
	mixChannels(image_m, 2, dst_m, 2, from_to, 6);
	imshow("ͨ�����һ", dst_m[0]);
	imshow("ͨ����϶�", dst_m[1]);
}