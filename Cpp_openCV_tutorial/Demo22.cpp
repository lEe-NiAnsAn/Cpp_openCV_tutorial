#include "23_histogram_equal.h"

void Demo22:: hist_eq_demo(Mat& image)
{
	Mat gray;
	//ֱ��ͼ���⻯��֧�ֵ�ͨ��ͼ��
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("ԭ�Ҷ�ͼ��", gray);
	Mat dst;
	equalizeHist(gray, dst);
	//ֱ��ͼ���⻯ʹ��ͼ��Աȶȼ�ǿ����һ���̶��Ͽ���ǿͼ��Ч��
	//ԭ��ͨ���㷨��ԭͼͳ�ƹ���ֱ��ͼ�ĻҶ�����������·��䣬ʹ�ø��Ҷ�������⻯
	imshow("ֱ��ͼ���⻯", dst);
}