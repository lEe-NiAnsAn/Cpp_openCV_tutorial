#include "21_histogram.h"	

void Demo20::histogram_demo(Mat& image)
{
	//三通道分离
	std::vector<Mat> bgr_plane;
	split(image, bgr_plane);
	//定义参数变量
	const int channels[1] = { 0 };	//待统计的通道
	const int bins[1] = { 256 };	//灰度取值区间顶
	float hranges[2] = { 0,255 };	//统计像素值区间
	const float* ranges[1] = { hranges };
	Mat b_hist, g_hist, r_hist;
	//计算BGR各通道数据
	//参数一：统计图像指针；参数二：图像数量；参数三：需要统计的通道；参数四：掩码；参数五：统计输出图像；
	//参数六：直方图维度；参数七：统计区间总个数的指针；参数八：统计像素值区间的指针；
	//参数九：是否归一化处理(默认:true)；参数十：多图像统计时是否累计计算(默认:false)
	//输出图像：为一张1*256大小的灰度图像，每一个像素点的灰度值即为统计得出的灰度值
	calcHist(&bgr_plane[0], 1, channels, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, channels, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, channels, Mat(), r_hist, 1, bins, ranges);
	//显示窗口
	int hist_w = 800;
	int hist_h = 480;
	int bin_w = cvRound((double)hist_w / bins[0]);	//cvRound()：对小数进行四舍五入为整数
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	//归一化数据
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	//绘制折线
	for (int i = 1; i < bins[0]; i++)
	{
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 1, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 1, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 1, 8, 0);
	}
	//显示折线图
	namedWindow("三通道色彩", WINDOW_AUTOSIZE);
	imshow("三通道色彩", histImage);
}
