//����openCV����>��ͼ\���Թ�����\_x64_opencv
/*
\VC++Ŀ¼��
1�����ð���Ŀ¼��	D:\openCV\opencv\build\include\opencv2
				D:\openCV\opencv\build\include
2�����ÿ�Ŀ¼��	D:\openCV\opencv\build\x64\vc16\lib

\������\���Ŀ¼��
3�����ø��������	D:\openCV\opencv\build\x64\vc16\lib\opencv_world480%~%.lib
					%~%lib������Release��Ϊ.lib��DebugΪd.lib
4�����û�������PATH��	D:\openCV\opencv\build\x64\vc16\bin
*/

#include <opencv2/opencv.hpp>

int main00(int argc, char** argv)
{
	cv::Mat src = cv::imread("test.jpg");
	if (src.empty())
	{
		std::cout << "�޷���ȡ��ͼ�񡭡�";
		return -1;
	}
	cv::imshow("��ȡ������ͼ��", src);
	cv::waitKey(0);

	return 0;
}
