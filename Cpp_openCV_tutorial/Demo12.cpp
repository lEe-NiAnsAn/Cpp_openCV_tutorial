#include "13_drawing_object.h"

void Demo12::drawing_demo(Mat& image)
{
	Mat mask = Mat::zeros(image.size(), image.type());
	Rect rt;	//�������ζ���
	rt.x = 110;
	rt.y = 80;
	rt.width = 100;
	rt.height = 100;	//�����ʼ������
	rectangle(mask, rt, Scalar(0, 200, 0), -1, 8, 0);

	//����Բ��(��������Բ�����ꣻ��������Բ�뾶)
	circle(mask, Point(160, 130), 20, Scalar(200, 0, 0), -1, LINE_AA, 0);	

	//�����߶�(���������߶���㣻���������߶��յ�)
	line(mask, Point(110, 80), Point(210, 180), Scalar(0, 0, 200), 1, 8, 0);
	line(mask, Point(210, 80), Point(110, 180), Scalar(0, 0, 200), 1, 8, 0);

	RotatedRect rrt;	//������Բ����
	rrt.center = Point(160, 180);
	rrt.size = Size(100, 50);	//(X��,Y��)����>��Բȫ�ᣬ���ǰ���
	rrt.angle = 0.0;	//��ת�Ƕ�(��ֵΪ��ʱ����ת)
	//������Բ
	ellipse(mask, rrt, Scalar(200, 0, 200), -1, LINE_AA);	//ֱ�ӻ���rrt����
	double startAngle = 60.0;	//��ʼ�Ƕ�Ĭ��Ϊ0.0�����Ҷ���
	double endAngle = 120.0;	//��ֹ�Ƕ�Ĭ��Ϊ360.0����ֵΪ˳ʱ����ת��90.0��Ϊ�¶���
	//(����������Բȫ�ᣬ���ǰ���)����>��ֱ��ʹ����Բ������Ʋ�ͬ��ȫ��/����;�������Ų���
	ellipse(mask, rrt.center, rrt.size, rrt.angle, startAngle, endAngle,
		Scalar(200, 200, 200), -1, LINE_AA,0);	//���������ĵ�����ʼ�Ƕ�ɨ����ֹ�Ƕȵ���Բ

	Mat dst;
	addWeighted(image, 0.618, mask, 0.382, 50, dst);
	imshow("����ͼ��", mask);
	imshow("�ϳ�ͼ��", dst);

	Mat bg1 = Mat::zeros(Size(512,512),CV_8UC3);
	RNG rng(12345);	//ʹ�ô�������Ӳ���һ��64λ����������飬����Ĭ��-1
	while (true)
	{
		int c = waitKey(166);
		if (c == 27) { std::cout << "�˳�\n"; break; }
		int x1 = rng.uniform(0, bg1.cols);	
		int y1 = rng.uniform(0, bg1.rows);	
		int x2 = rng.uniform(0, bg1.cols);	
		int y2 = rng.uniform(0, bg1.rows);	
		int b = rng.uniform(0, 255);
		int g = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);	//����������������ڵ����Ρ���>α���
		line(bg1, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 1, LINE_AA, 0);
		imshow("�������", bg1);
	}

	Mat bg2 = Mat::zeros(Size(512, 512), CV_8UC3);
	Hexagon hg(200, Point(250, 250));	//ͨ���Խ����������ഴ������
	//(Ŀ��ͼ��,��������,�����ɫ,���������,���Ų���)����>�������
	fillPoly(bg2, hg.m_v, Scalar(240, 190, 145), 8, 0);
	//(Ŀ��ͼ��,��������,�Ƿ�����,�߿���ɫ,�߿�,���������,���Ų���)����>���ɻ��Ʊ߿�
	polylines(bg2, hg.m_v, true, Scalar(0, 0, 200), 2, LINE_AA, 0);
	imshow("����λ���", bg2);

	Mat bg3 = Mat::zeros(Size(512, 512), CV_8UC3);
	std::vector<std::vector<Point>> contous;	//��������������������
	for (int i = 0; i < 3; i++)
	{
		int y = 120 + i * 150;
		Hexagon hg(60, Point(250, y));
		contous.push_back(hg.m_v);
	}
	//(Ŀ��ͼ��,����,����Ŀ������,��ɫ,�߿�,���������)����>���ܣ��ɻ��Ʊ߿�������
	drawContours(bg3, contous, -1, Scalar(240, 190, 145), -1, 8);
	//���������ڵ���0�����������Ӧλ��ͼ�Σ�С������ȫ�����ƣ�
	imshow("��ͼ�λ���", bg3);
}
