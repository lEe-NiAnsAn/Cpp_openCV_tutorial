#include "24_convolution.h"

void Demo23:: blur_demo(Mat& image)
{
	//卷积操作：
	/*
	通过一个自订的卷积窗口/核(填充了权重值的矩阵)，处理图像像素；
	在卷积处理时，以锚定点(卷积窗口中心)为中心的卷积核面积内像素点将与对应卷积核内权重相乘，
	再将乘积累加后除以卷积核面积大小得到新值并赋给锚定点或卷积核中指定位置对应的坐标；
	卷积操作将依次沿X、Y轴方向遍历图像像素点，但因存在卷积核半径故图像边缘像素无法处理；
	卷积操作一般也需要提供边缘处理算法
	*/
	Mat dst;
	//blur()：卷积核内权重值均为1，卷积操作使得图像像素趋同实现模糊处理
	blur(image, dst, Size(6, 6));	//卷积核越大越模糊
	//参数一：输入图像；参数二：输出图像；参数三：卷积核大小；
	//参数四：操作坐标(默认:Point(-1,-1)锚定点)；参数五：边缘处理模式(默认:BORDER_DEFAULT)
	imshow("均值模糊", dst);

	//高斯模糊：通过高斯函数获取卷积核
	GaussianBlur(image, dst, Size(7, 7), 7.0);	//此处卷积核大小必须为正奇数边长
	//参数一：输入图像；参数二：输出图像；参数三：卷积核大小；
	//参数四：X方向滤波系数；参数五：Y方向滤波系数(默认:0.0即为与X方向相等)；
	//参数六：边缘处理模式(默认:BORDER_DEFAULT)
	//若Size(0,0)，则将根据XY方向滤波系数大小自动设置卷积核大小
	imshow("高斯模糊", dst);
	
	//高斯双边模糊：在模糊的同时保留原图像的边界细节——>去噪点操作
	//通过坐标空间与色彩空间双边权重合成新卷积核，使得在颜色差异大的区域卷积核内权重较小
	bilateralFilter(image, dst, 0, 200, 10);
	//参数一：输入图像；参数二：输出图像；参数三：卷积核半径；
	//参数四：色彩空间滤波系数；参数五：坐标空间滤波系数；参数六：边缘处理模式
	//卷积核半径为非正数时即通过坐标空间滤波系数决定
	//色彩空间滤波系数越大，色彩相近的区域模糊程度越高
	//坐标空间滤波系数越大，模糊度越高
	imshow("双边模糊", dst);
}
