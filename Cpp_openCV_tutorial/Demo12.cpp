#include "13_drawing_object.h"

void Demo12::drawing_demo(Mat& image)
{
	Mat mask = Mat::zeros(image.size(), image.type());
	Rect rt;	//创建矩形对象
	rt.x = 110;
	rt.y = 80;
	rt.width = 100;
	rt.height = 100;	//逐项初始化矩形
	rectangle(mask, rt, Scalar(0, 200, 0), -1, 8, 0);

	//绘制圆形(参数二：圆心坐标；参数三：圆半径)
	circle(mask, Point(160, 130), 20, Scalar(200, 0, 0), -1, LINE_AA, 0);	

	//绘制线段(参数二：线段起点；参数三：线段终点)
	line(mask, Point(110, 80), Point(210, 180), Scalar(0, 0, 200), 1, 8, 0);
	line(mask, Point(210, 80), Point(110, 180), Scalar(0, 0, 200), 1, 8, 0);

	RotatedRect rrt;	//创建椭圆对象
	rrt.center = Point(160, 180);
	rrt.size = Size(100, 50);	//(X轴,Y轴)——>椭圆全轴，而非半轴
	rrt.angle = 0.0;	//旋转角度(正值为逆时针旋转)
	//绘制椭圆
	ellipse(mask, rrt, Scalar(200, 0, 200), -1, LINE_AA);	//直接绘制rrt对象
	double startAngle = 60.0;	//起始角度默认为0.0，即右顶点
	double endAngle = 120.0;	//终止角度默认为360.0：正值为顺时针旋转，90.0则为下顶点
	//(参数三：椭圆全轴，而非半轴)——>与直接使用椭圆对象绘制不同：全轴/半轴;有无缩放参数
	ellipse(mask, rrt.center, rrt.size, rrt.angle, startAngle, endAngle,
		Scalar(200, 200, 200), -1, LINE_AA,0);	//绘制由中心点自起始角度扫至终止角度的椭圆

	Mat dst;
	addWeighted(image, 0.618, mask, 0.382, 50, dst);
	imshow("绘制图像", mask);
	imshow("合成图像", dst);

	Mat bg1 = Mat::zeros(Size(512,512),CV_8UC3);
	RNG rng(12345);	//使用传入的种子产生一个64位随机整形数组，种子默认-1
	while (true)
	{
		int c = waitKey(166);
		if (c == 27) { std::cout << "退出\n"; break; }
		int x1 = rng.uniform(0, bg1.cols);	
		int y1 = rng.uniform(0, bg1.rows);	
		int x2 = rng.uniform(0, bg1.cols);	
		int y2 = rng.uniform(0, bg1.rows);	
		int b = rng.uniform(0, 255);
		int g = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);	//均匀随机产生区间内的整形——>伪随机
		line(bg1, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 1, LINE_AA, 0);
		imshow("随机绘制", bg1);
	}

	Mat bg2 = Mat::zeros(Size(512, 512), CV_8UC3);
	Hexagon hg(200, Point(250, 250));	//通过自建正六边形类创建对象
	//(目标图像,顶点容器,填充颜色,抗锯齿类型,缩放参数)——>仅可填充
	fillPoly(bg2, hg.m_v, Scalar(240, 190, 145), 8, 0);
	//(目标图像,顶点容器,是否相连,边框颜色,线宽,抗锯齿类型,缩放参数)——>仅可绘制边框
	polylines(bg2, hg.m_v, true, Scalar(0, 0, 200), 2, LINE_AA, 0);
	imshow("多边形绘制", bg2);

	Mat bg3 = Mat::zeros(Size(512, 512), CV_8UC3);
	std::vector<std::vector<Point>> contous;	//储存多个顶点容器的容器
	for (int i = 0; i < 3; i++)
	{
		int y = 120 + i * 150;
		Hexagon hg(60, Point(250, y));
		contous.push_back(hg.m_v);
	}
	//(目标图像,容器,绘制目标索引,颜色,线宽,抗锯齿类型)——>功能：可绘制边框，亦可填充
	drawContours(bg3, contous, -1, Scalar(240, 190, 145), -1, 8);
	//索引：大于等于0则绘制容器对应位置图形，小于零则全部绘制；
	imshow("多图形绘制", bg3);
}
