#include "08_color_style.h"

void Demo7::color_style_demo(Mat& image)
{
	//创建色彩风格数组，详见文档(目前为22种)
	int colormap[] =
	{
		COLORMAP_AUTUMN,
		COLORMAP_BONE,
		COLORMAP_JET,
		COLORMAP_WINTER,
		COLORMAP_RAINBOW,
		COLORMAP_OCEAN,
		COLORMAP_SUMMER,
		COLORMAP_SPRING,
		COLORMAP_COOL,
		COLORMAP_HSV,
		COLORMAP_PINK,
		COLORMAP_HOT,
		COLORMAP_PARULA,
		COLORMAP_MAGMA,
		COLORMAP_INFERNO,
		COLORMAP_PLASMA,
		COLORMAP_VIRIDIS,
		COLORMAP_CIVIDIS,
		COLORMAP_TWILIGHT,
		COLORMAP_TWILIGHT_SHIFTED,
		COLORMAP_TURBO,
		COLORMAP_DEEPGREEN
	};
	std::string colorstype[] = 
	{	"金秋","骨灰","喷枪","寒冬","彩虹","海蓝","盛夏","暖春","冰冷","HSV","粉红",
		"炎热","森莺","熔岩","地狱","血红","翠绿","青黛","黄昏","浅夜","漩涡","深绿" };
	Mat dst = Mat::zeros(image.size(), image.type());
	int i = 0;
	while (true)
	{
		int c = waitKey(1314);
		if (c == 27) { std::cout << "退出\n"; break; }
		applyColorMap(image, dst, colormap[i % 22]);	//模22即在0~21间取值
		std::cout << colorstype[i % 22] << std::endl;
		i++;
		imshow("颜色风格", dst);
	}
}
