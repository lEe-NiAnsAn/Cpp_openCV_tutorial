#include "17_flip_operation.h"

void Demo16::flip_demo(Mat& image)
{
	Mat dst;
	flip(image, dst, 0);	//µßµ¹
	imshow("Í¼Ïñµßµ¹", dst);
	flip(image, dst, 1);	//¾µÏñ
	imshow("Í¼Ïñ¾µÏñ", dst);
	flip(image, dst, -1);	//ÖÐÐÄ¶Ô×ª
	imshow("Í¼ÏñÖÐÐÄ¶Ô×ª", dst);
}
