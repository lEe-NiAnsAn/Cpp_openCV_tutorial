#include "03_creat_matrix.h"

void Demo2::mat_creation_demo(Mat& image)
{
	Mat m1, m2;
	m1 = image.clone();	//克隆图像对象
	image.copyTo(m2);	//深拷贝图像对象

	Mat m3 = Mat::ones(Size(8, 8), CV_8UC2);	//创建空图像对象
	//CV_8UC1——>8：八位；U：无符号；C2：双通道
	//八位单通道即8*8，八位双通道即(8*2)*8
	//zeros：矩阵内所有值均为0
	//ones：矩阵内首通道为1，其余通道为0
	int w = m3.cols;	//矩阵宽(列)
	int h = m3.rows;	//矩阵高(行)
	int c = m3.channels();	//通道数
	std::cout << "(" << w  << "*" << c << ") * " << h << "\n";
	std::cout << m3 << "s\n\n";	//打印输出图像对象矩阵数据
	m3 = 127;	//将矩阵首通道所有值赋为127
	m3 = Scalar(127, 127);	//将矩阵前两通道所有值赋为127
	std::cout << m3 << std::endl;

	Mat m4 = Mat::zeros(Size(4096, 3112), CV_8UC3);
	m4 = Scalar(240, 190, 145);	//默认前三通道为BGR颜色空间
	namedWindow("创建图像", WINDOW_FREERATIO);	//可调整合适尺寸窗口尺寸显示4k图像
	imshow("创建图像", m4);	//显示所创建图像
	imwrite("Bule.jpg", m4);	//保存所创建图像

	Mat m5;
	std::cout << m3 << std::endl;
	m5 = m3;
	m5 = Scalar(240, 0);	//简单赋值为浅拷贝
	std::cout << m3 << std::endl;	//更改m5即更改m3

	Mat m6 = (Mat_<char>(3, 3) << 
		3, -1, 4,
		1, 5, 9,
		2, 6, 0);	//通过模板类与重载<<运算符创建Mat
	std::cout << m6 << "\n";
}