//Mat������headerͷ����DataBlock���ݲ������
//header�洢Mat�����ݵ����������Եȣ���ָ���ӦDataBlock
//��ֵʱ��������headerָ��ͬһDataBlock����¡ʱ����ȫ����DataBlock
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include "03_creat_matrix.h"

int main03(int argc, char** argv)
{
	Mat src = imread("test01.png");
	if (src.empty())
	{
		cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}

	Demo2 d02;
	d02.mat_creation_demo(src);	//���ó�Ա������¡����������ӡ���ͼ�����

	imshow("����ͼ��", src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}