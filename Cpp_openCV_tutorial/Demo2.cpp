#include "03_creat_matrix.h"

void Demo2::mat_creation_demo(Mat& image)
{
	Mat m1, m2;
	m1 = image.clone();	//��¡ͼ�����
	image.copyTo(m2);	//���ͼ�����

	Mat m3 = Mat::ones(Size(8, 8), CV_8UC2);	//������ͼ�����
	//CV_8UC1����>8����λ��U���޷��ţ�C2��˫ͨ��
	//��λ��ͨ����8*8����λ˫ͨ����(8*2)*8
	//zeros������������ֵ��Ϊ0
	//ones����������ͨ��Ϊ1������ͨ��Ϊ0
	int w = m3.cols;	//�����(��)
	int h = m3.rows;	//�����(��)
	int c = m3.channels();	//ͨ����
	std::cout << "(" << w  << "*" << c << ") * " << h << "\n";
	std::cout << m3 << "s\n\n";	//��ӡ���ͼ������������
	m3 = 127;	//��������ͨ������ֵ��Ϊ127
	m3 = Scalar(127, 127);	//������ǰ��ͨ������ֵ��Ϊ127
	std::cout << m3 << std::endl;

	Mat m4 = Mat::zeros(Size(4096, 3112), CV_8UC3);
	m4 = Scalar(240, 190, 145);	//Ĭ��ǰ��ͨ��ΪBGR��ɫ�ռ�
	namedWindow("����ͼ��", WINDOW_FREERATIO);	//�ɵ������ʳߴ細�ڳߴ���ʾ4kͼ��
	imshow("����ͼ��", m4);	//��ʾ������ͼ��
	imwrite("Bule.jpg", m4);	//����������ͼ��

	Mat m5;
	std::cout << m3 << std::endl;
	m5 = m3;
	m5 = Scalar(240, 0);	//�򵥸�ֵΪǳ����
	std::cout << m3 << std::endl;	//����m5������m3

	Mat m6 = (Mat_<char>(3, 3) << 
		3, -1, 4,
		1, 5, 9,
		2, 6, 0);	//ͨ��ģ����������<<���������Mat
	std::cout << m6 << "\n";
}