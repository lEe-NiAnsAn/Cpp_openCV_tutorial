#include "14_mouse_operation.h"

Point start_p(-1, -1);
Point end_p(-1, -1);
Mat temp;
static void on_draw(int event, int x, int y, int flag, void* userdata)
{//(����¼�,���X��λ��,���Y��λ��,���״̬,�ص�����)
	Mat dst = *((Mat*)userdata);
	if (event == EVENT_LBUTTONDOWN)	//�������
	{
		start_p.x = x;
		start_p.y = y;
	}
	else if (event == EVENT_LBUTTONUP)	//�ɿ����
	{
		end_p.x = x;
		end_p.y = y;
		int delta_x = end_p.x - start_p.x;
		int delta_y = end_p.y - start_p.y;
		if (delta_x > 0 && delta_y > 0)
		{
			Rect box(start_p.x, start_p.y, delta_x, delta_y);	//�������ζ���
			imshow("ѡ������", temp(box));
			//Mat(Rect)����Rect�е������ȡMat�����򴴽���ͼ�����
			rectangle(dst, box, Scalar(0, 0, 200), 1, 8, 0);
			imshow("������", dst);
		}
		start_p.x = -1;
		start_p.y = -1;	//��������
	}
	else if (event == EVENT_MOUSEMOVE)	//����ƶ�
	{
		if (start_p.x > 0 && start_p.y > 0)	//ʵ����������
		{
			end_p.x = x;
			end_p.y = y;
			int delta_x = end_p.x - start_p.x;
			int delta_y = end_p.y - start_p.y;
			if (delta_x > 0 && delta_y > 0)
			{
				temp.copyTo(dst);
				Rect box(start_p.x, start_p.y, delta_x, delta_y);
				rectangle(dst, box, Scalar(0, 0, 200), 1, 8, 0);
				imshow("������", dst);
			}
		}
	}
}
void Demo13::mouse_drawing_demo(Mat& image)
{
	namedWindow("������", WINDOW_AUTOSIZE);
	//(Ŀ�괰��,�ص�����,�ص�����)
	setMouseCallback("������", on_draw, &image);
	imshow("������", image);
	temp = image.clone();	//image�ݴ���temp
}
