#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//imread(ͼ��洢·��/�ļ���,��ʾɫ��)����>��ȡͼ��·��Ĭ��Ϊ��Ŀ�����ļ��У�
												  //ĩ����δ��Ĭ��ΪIMREAD_COLOR(��ɫ)
	//Mat(matrix����)��ͼ�����������
	Mat src1 = imread("test01.png",IMREAD_GRAYSCALE);	//�ԻҶ�ͼ���
	if (src1.empty())	//�ж��Ƿ��ͼ��
	{
		cout << "δ��ȡ��ͼ�񡭡�\n";
		return -1;
	}

	namedWindow("test01", WINDOW_FREERATIO);	//�������ɱ������ڣ�������ʾ��ͼ(��������)
	//imshow(��ʾ��������,��ʾ������)����>��ʾͼ��
	imshow("test01", src1);	//��ʾ����ǰ���������ɱ�������

	waitKey(0);	//��ͣ����>����Ϊ0ʱ�������ͣ������Ϊ��������ͣ��λ����ʱ��
	destroyAllWindows();	//�ر�����ͼ�񴰿�

	return 0;
}