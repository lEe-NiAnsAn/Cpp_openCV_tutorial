#include <iostream>
#include <opencv2/opencv.hpp>
#include "02_operation.h"
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("test01.png");
	if (src.empty())
	{
		cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}
	
	Demo1 d01;
	d01.colorSpace_Demo(src);	//���ó�Ա����ת��ɫ�ʿռ�

	imshow("����ͼ��", src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}