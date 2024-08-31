#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//imread(图像存储路径/文件名,显示色彩)——>读取图像，路径默认为项目所在文件夹；
												  //末参数未传默认为IMREAD_COLOR(彩色)
	//Mat(matrix矩阵)：图像对象所属类
	Mat src1 = imread("test01.png",IMREAD_GRAYSCALE);	//以灰度图像打开
	if (src1.empty())	//判断是否打开图像
	{
		cout << "未读取到图像……\n";
		return -1;
	}

	namedWindow("test01", WINDOW_FREERATIO);	//创建自由比例窗口，便于显示大图(比例不定)
	//imshow(显示窗口名称,显示对象名)——>显示图像
	imshow("test01", src1);	//显示在先前创建的自由比例窗口

	waitKey(0);	//暂停——>参数为0时则持续暂停，参数为正数则暂停单位毫秒时间
	destroyAllWindows();	//关闭所有图像窗口

	return 0;
}