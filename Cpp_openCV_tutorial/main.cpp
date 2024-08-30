//配置openCV:——>视图\属性管理器\_x64_opencv
/*
\VC++目录
1、配置包含目录：	D:\openCV\opencv\build\include\opencv2
				D:\openCV\opencv\build\include
2、配置库目录：	D:\openCV\opencv\build\x64\vc16\lib
链接器\输出目录
3、配置附加依赖项：D:\openCV\opencv\build\x64\vc16\lib\opencv_world480%~%.lib
				 %~%lib：配置Release则为.lib；Debug为d.lib
4、配置环境变量并重启VS
*/

#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat src = cv::imread("D:/user/Pictures/Saved Pictures/test.jpg");
	if (src.empty())
	{
		std::cout << "无法读取到图像……";
		return -1;
	}
	cv::imshow("输入图像", src);
	cv::waitKey(0);

	return 0;
}
