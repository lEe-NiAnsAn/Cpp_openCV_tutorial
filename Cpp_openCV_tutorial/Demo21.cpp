#include "22_histogram_2d.h"

void Demo21::histogram2d_demo(Mat& image)
{
	Mat hsv, hs_hist;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	int channels[2] = { 0,1 };
	int h_bins = 181;
	int s_bins = 256;
	int hist_bins[2] = { h_bins,s_bins };
	float h_range[2] = { 0,180 };
	float s_range[2] = { 0,255 };
	const float* hs_ranges[2] = { h_range,s_range };
	calcHist(&hsv, 1, channels, Mat(), hs_hist, 2, hist_bins, hs_ranges);
	double max_v = 0.0;
	minMaxLoc(hs_hist, 0, &max_v, 0, 0);	//统计最大值
	//参数一：统计图像；参数二：最小值存储处；参数三：最大值存储处；
	//参数四：最小值坐标存储处；参数五：最大值坐标存储处；参数六：掩码(默认:空)
	int scale = 3;
	Mat hist2d = Mat::zeros(h_bins*scale, s_bins * scale, CV_8UC3);
	for (int h = 0; h < h_bins; h++)
	{
		for (int s = 0; s < s_bins; s++)
		{
			float bin_v = hs_hist.at<float>(h, s);
			int intensity = cvRound(bin_v * 255 / max_v);	//通过最大值进行灰度归一化
			rectangle(hist2d, Point(h * scale, s * scale), 
				Point((h + 1) * scale - 1, (s + 1) * scale - 1), 
				Scalar::all(intensity), -1);
			//Scalar::all(int)<=>Scalar(int,int,int)
			//以步长(即总长除以总小区间数)绘制一个个直方图中的“像素”达到可视化
			//intensity即为“像素”的灰度
		}
	}
	namedWindow("HSV色彩", WINDOW_AUTOSIZE);
	applyColorMap(hist2d, hist2d, COLORMAP_TURBO);
	imshow("HSV色彩", hist2d);
}
