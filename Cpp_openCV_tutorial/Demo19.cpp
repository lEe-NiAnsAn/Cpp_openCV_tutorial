#include "20_video_save.h"

void Demo19::videos_demo(Mat& image)
{
	VideoCapture capture("sing.mp4");
	double frame_w = capture.get(CAP_PROP_FRAME_WIDTH);	//��Ƶ��
	double frame_h = capture.get(CAP_PROP_FRAME_HEIGHT);	//��Ƶ��
	double frame_c = capture.get(CAP_PROP_FRAME_COUNT);	//��Ƶ֡����
	double fps = capture.get(CAP_PROP_FPS);	//��Ƶ֡��
	std::cout  << "��Ƶ֡������" << frame_c << "  �ֱ��ʣ�" << frame_w << "*" << frame_h << "  ��Ƶ֡�ʣ�" << fps << std::endl;
	VideoWriter writer("��ɫ.mp4", capture.get(CAP_PROP_FOURCC),fps,Size(frame_w/2,frame_h/2),true);	//�������������
	//����һ�������ļ���������������������ʽ��������������֡�ʣ������ģ�����ֱ��ʴ�С�������壺�Ƿ�Ϊ��ɫ
	Mat frame;
	while (true)
	{
		capture.read(frame);
		if (frame.empty())
		{
			std::cout << "��Ƶ���Ž�����\n";
			return;
		};
		resize(frame, frame, Size(), 0.5, 0.5);
		int w = frame.cols;
		int h = frame.rows;
		for (int row = 0; row < h; row++)
		{
			uchar* current_row = frame.ptr<uchar>(row);
			for (int col = 0; col < w; col++)
			{
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
		imshow("��Ƶ��ɫ", frame);
		writer.write(frame);	//����ȱ��.dll�ļ��������غ���������������ļ���
		int c = waitKey(1);
		if (c == 27) { std::cout << "�˳�\n"; break; }
	}
	capture.release();
	writer.release();	//�ͷű��������

}