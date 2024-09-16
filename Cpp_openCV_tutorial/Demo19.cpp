#include "20_video_save.h"

void Demo19::videos_demo(Mat& image)
{
	VideoCapture capture("sing.mp4");
	double frame_w = capture.get(CAP_PROP_FRAME_WIDTH);	//视频宽
	double frame_h = capture.get(CAP_PROP_FRAME_HEIGHT);	//视频高
	double frame_c = capture.get(CAP_PROP_FRAME_COUNT);	//视频帧总数
	double fps = capture.get(CAP_PROP_FPS);	//视频帧率
	std::cout  << "视频帧总数：" << frame_c << "  分辨率：" << frame_w << "*" << frame_h << "  视频帧率：" << fps << std::endl;
	VideoWriter writer("反色.mp4", capture.get(CAP_PROP_FOURCC),fps,Size(frame_w/2,frame_h/2),true);	//创建保存类对象
	//参数一：保存文件名；参数二：保存编码格式；参数三：保存帧率；参数四：保存分辨率大小；参数五：是否为彩色
	Mat frame;
	while (true)
	{
		capture.read(frame);
		if (frame.empty())
		{
			std::cout << "视频播放结束！\n";
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
		imshow("视频反色", frame);
		writer.write(frame);	//可能缺少.dll文件，需下载后添加至环境变量文件夹
		int c = waitKey(1);
		if (c == 27) { std::cout << "退出\n"; break; }
	}
	capture.release();
	writer.release();	//释放保存类对象

}