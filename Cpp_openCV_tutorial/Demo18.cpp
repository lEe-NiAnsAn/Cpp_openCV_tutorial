#include "19_view_video.h"

void Demo18::video_demo(Mat& image)
{
	VideoCapture capture("sing.mp4");	//参数为0则为读取设备的摄像头
	Mat frame;
	while (true)
	{
		capture.read(frame);
		if (frame.empty()) 
		{
			std::cout << "视频播放结束！\n"; 
			return ;
		};
		resize(frame, frame, Size(),0.5,0.5);
		resize(image, image, frame.size());
		Mat temp, hsv;
		temp = frame.clone();
		cvtColor(frame, hsv, COLOR_BGR2HSV);
		Mat mask;
		inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);
		image.copyTo(frame, mask);
		imshow("视频扣绿幕", frame);

		int w = temp.cols;
		int h = temp.rows;
		for (int row = 0; row < h; row++)
		{
			uchar* current_row = temp.ptr<uchar>(row);
			for (int col = 0; col < w; col++)
			{
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
		imshow("视频反色", temp);
		int c = waitKey(1);
		if (c == 27) { std::cout << "退出\n"; break; }
	}
	capture.release();	//释放相机资源
}