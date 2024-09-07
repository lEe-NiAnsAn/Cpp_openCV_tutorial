#include "08_color_style.h"

void Demo7::color_style_demo(Mat& image)
{
	//����ɫ�ʷ�����飬����ĵ�(ĿǰΪ22��)
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
	{	"����","�ǻ�","��ǹ","����","�ʺ�","����","ʢ��","ů��","����","HSV","�ۺ�",
		"����","ɭݺ","����","����","Ѫ��","����","����","�ƻ�","ǳҹ","����","����" };
	Mat dst = Mat::zeros(image.size(), image.type());
	int i = 0;
	while (true)
	{
		int c = waitKey(1314);
		if (c == 27) { std::cout << "�˳�\n"; break; }
		applyColorMap(image, dst, colormap[i % 22]);	//ģ22����0~21��ȡֵ
		std::cout << colorstype[i % 22] << std::endl;
		i++;
		imshow("��ɫ���", dst);
	}
}
