#include "19_view_video.h"

void Demo18::video_demo(Mat& image)
{
	VideoCapture capture("sing.mp4");	//����Ϊ0��Ϊ��ȡ�豸������ͷ
	Mat frame;
	while (true)
	{
		capture.read(frame);
		if (frame.empty()) 
		{
			std::cout << "��Ƶ���Ž�����\n"; 
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
		imshow("��Ƶ����Ļ", frame);

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
		imshow("��Ƶ��ɫ", temp);
		int c = waitKey(1);
		if (c == 27) { std::cout << "�˳�\n"; break; }
	}
	capture.release();	//�ͷ������Դ
}