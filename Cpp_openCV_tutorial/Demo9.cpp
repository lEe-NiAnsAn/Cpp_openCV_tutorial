#include "10_channels_operation.h"

void Demo9::channels_demo(Mat& image)
{
	std::vector<Mat> mv;	//通过Mat的vector容器进行存储
	split(image, mv);
	imshow("B通道灰度", mv[0]);
	imshow("G通道灰度", mv[1]);
	imshow("R通道灰度", mv[2]);

	Mat dst;
	std::vector<Mat> temp1;
	split(image, temp1);
	temp1[1] = 0; temp1[2] = 0;
	merge(temp1, dst);	//置空另外两通道进行合成
	imshow("蓝色通道", dst);
	std::vector<Mat> temp2;
	split(image, temp2);
	temp2[0] = 0; temp2[2] = 0;
	merge(temp2, dst);	
	imshow("绿色通道", dst);
	std::vector<Mat> temp3;
	split(image, temp3);
	temp3[1] = 0; temp3[0] = 0;
	merge(temp3, dst);	
	imshow("红色通道", dst);

	int from_to[] =
	{	0,1,
		1,2,
		2,0,
		3,5,
		4,3,
		5,4	};	//两两成对交换
	//0~2为dst1/前image三通道，3~5为dst2/后image三通道
	Mat dst1, dst2;
	dst1 = Mat::zeros(image.size(), image.type());
	dst2 = Mat::zeros(image.size(), image.type());
	Mat image_m[] = { image,image };
	Mat dst_m[] = { dst1,dst2 };
	//(源图像数组,图像数量,目标图像引用数组,图像数量,映射对数组,映射对数量)
	mixChannels(image_m, 2, dst_m, 2, from_to, 6);
	imshow("通道混合一", dst_m[0]);
	imshow("通道混合二", dst_m[1]);
}