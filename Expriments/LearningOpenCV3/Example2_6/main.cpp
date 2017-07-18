#include <opencv2/opencv.hpp>

using namespace cv;
const char EXAMPLE_WINDOW1[] = "Example1";
const char EXAMPLE_WINDOW2[] = "Example2";

//利用pyDown来创建一个宽高减半的图像
int main(int argc, char** argv) {
	//第2个参数flag， 可以指定图片的颜色模式。 -1为unchanged，默认值为1,彩色模式
	//Mat img = imread(argv[1], -1);
	Mat img = imread("C:\\Users\\weixi\\Pictures\\lena.bmp", CV_LOAD_IMAGE_UNCHANGED);
	if (img.empty()) return -1;

	namedWindow(EXAMPLE_WINDOW1, cv::WINDOW_AUTOSIZE);
	namedWindow(EXAMPLE_WINDOW2, cv::WINDOW_AUTOSIZE);

	imshow(EXAMPLE_WINDOW1, img);
	Mat img2;
	pyrDown(img, img2);
	imshow(EXAMPLE_WINDOW2, img2);

	waitKey(0);

}