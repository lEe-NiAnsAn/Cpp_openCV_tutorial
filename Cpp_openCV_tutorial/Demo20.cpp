#include "21_histogram.h"	

void Demo20::histogram_demo(Mat& image)
{
	//��ͨ������
	std::vector<Mat> bgr_plane;
	split(image, bgr_plane);
	//�����������
	const int channels[1] = { 0 };	//��ͳ�Ƶ�ͨ��
	const int bins[1] = { 256 };	//�Ҷ�ȡֵ���䶥
	float hranges[2] = { 0,255 };	//ͳ������ֵ����
	const float* ranges[1] = { hranges };
	Mat b_hist, g_hist, r_hist;
	//����BGR��ͨ������
	//����һ��ͳ��ͼ��ָ�룻��������ͼ������������������Ҫͳ�Ƶ�ͨ���������ģ����룻�����壺ͳ�����ͼ��
	//��������ֱ��ͼά�ȣ������ߣ�ͳ�������ܸ�����ָ�룻�����ˣ�ͳ������ֵ�����ָ�룻
	//�����ţ��Ƿ��һ������(Ĭ��:true)������ʮ����ͼ��ͳ��ʱ�Ƿ��ۼƼ���(Ĭ��:false)
	//���ͼ��Ϊһ��1*256��С�ĻҶ�ͼ��ÿһ�����ص�ĻҶ�ֵ��Ϊͳ�Ƶó��ĻҶ�ֵ
	calcHist(&bgr_plane[0], 1, channels, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, channels, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, channels, Mat(), r_hist, 1, bins, ranges);
	//��ʾ����
	int hist_w = 800;
	int hist_h = 480;
	int bin_w = cvRound((double)hist_w / bins[0]);	//cvRound()����С��������������Ϊ����
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	//��һ������
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	//��������
	for (int i = 1; i < bins[0]; i++)
	{
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 1, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 1, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 1, 8, 0);
	}
	//��ʾ����ͼ
	namedWindow("��ͨ��ɫ��", WINDOW_AUTOSIZE);
	imshow("��ͨ��ɫ��", histImage);
}
