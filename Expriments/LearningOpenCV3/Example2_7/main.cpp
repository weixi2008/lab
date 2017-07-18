#include <opencv2/opencv.hpp>

using namespace cv;
const char EXAMPLE_WINDOW1[] = "Example1";
const char EXAMPLE_WINDOW2[] = "Example2";

//使用Canny取得边缘
int main(int argc, char** argv) {
	//第2个参数flag， 可以指定图片的颜色模式。 -1为unchanged，默认值为1,彩色模式
	//Mat img = imread(argv[1], -1);
	Mat img = imread("C:\\Users\\weixi\\Pictures\\lena.bmp", CV_LOAD_IMAGE_UNCHANGED);
	if (img.empty()) return -1;

	namedWindow(EXAMPLE_WINDOW1, cv::WINDOW_AUTOSIZE);
	namedWindow(EXAMPLE_WINDOW2, cv::WINDOW_AUTOSIZE);

	Mat img_gry, img_cny;
	cvtColor(img, img_gry, COLOR_BGR2GRAY);
	imshow(EXAMPLE_WINDOW1, img_gry);

	Canny(img_gry, img_cny, 10, 100, 3, true);
	imshow(EXAMPLE_WINDOW2, img_cny);


	waitKey(0);

}