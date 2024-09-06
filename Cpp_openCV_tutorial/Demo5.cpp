#include "06_tracking_bar.h"

int a;
int b;
static int* ptr_l = &a;
static int* ptr_c = &b;
static void on_track_l(int light, void* userdata)
{
    Mat dst, mo, image, temp;
    image = *((Mat*)userdata);
    dst = Mat::zeros(image.size(), image.type());
    mo = Mat::zeros(image.size(), image.type());
    temp = Mat::zeros(image.size(), image.type());
    //同步对比度
    *ptr_l = light;
    if (*ptr_c >= 50)
    {
        double p_c = (*ptr_c - 50) / 50.0 + 1.0;
        addWeighted(image, p_c, mo, 0, 0, dst);
    }
    else
    {
        double n_c = 1.0 - (50 - *ptr_c) / 50.0;
        addWeighted(image, n_c, mo, 0.0, 0, dst);
    }

    if (light > 50) // 变亮
    {
        mo = Scalar((light - 50) * 2, (light - 50) * 2, (light - 50) * 2);
        add(dst, mo, temp);
    }
    else // 变暗
    {
        mo = Scalar((50 - light) * 2, (50 - light) * 2, (50 - light) * 2);
        subtract(dst, mo, temp);
    }
    imshow("调整", temp);
}

static void on_track_c(int contrast, void* userdata)
{
    Mat dst, mo, image, temp;
    image = *((Mat*)userdata);
    dst = Mat::zeros(image.size(), image.type());
    mo = Mat::zeros(image.size(), image.type());
    temp = Mat::zeros(image.size(), image.type());

    if (contrast >= 50) // 提高对比度
    {
        double p_c = (contrast - 50) / 50.0 + 1.0;
        addWeighted(image, p_c, mo, 0, 0, dst);
    }
    else // 降低对比度
    {
        double n_c = 1.0 - (50 - contrast) / 50.0;
        addWeighted(image, n_c, mo, 0.0, 0, dst);
    }

    //同步亮度
    *ptr_c = contrast;
    if (*ptr_l > 50)
    {
        mo = Scalar((*ptr_l - 50) * 2, (*ptr_l - 50) * 2, (*ptr_l - 50) * 2);
        add(dst, mo, temp);
    }
    else
    {
        mo = Scalar((50 - *ptr_l) * 2, (50 - *ptr_l) * 2, (50 - *ptr_l) * 2);
        subtract(dst, mo, temp);
    }

    imshow("调整", temp);
}

void Demo5::tracking_bar_demo(Mat& image)
{
    namedWindow("调整", WINDOW_AUTOSIZE);
    // 调整亮度
    int now_l = 50; // 设置原亮度值
    int max_l = 100; // 设置最大亮度值
    on_track_l(now_l, &image); // 向操作函数传参
    createTrackbar("亮度", "调整", &now_l, max_l, on_track_l, &image);
    // 创建滑块|参数一：滑块名；参数二：显示窗口；参数三：待更改值；参数四：最大值(最小值0)
    // 参数五：操作函数——>固定参数

    // 调整对比度
    int now_c = 50; // 设置原对比度值
    on_track_c(now_l, &image);
    createTrackbar("对比度", "调整", &now_c, max_l, on_track_c, &image);
}