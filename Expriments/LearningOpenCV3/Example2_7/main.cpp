#include <opencv2/opencv.hpp>

using namespace cv;
const char EXAMPLE_WINDOW1[] = "Example1";
const char EXAMPLE_WINDOW2[] = "Example2";

//ʹ��Cannyȡ�ñ�Ե
int main(int argc, char** argv) {
	//��2������flag�� ����ָ��ͼƬ����ɫģʽ�� -1Ϊunchanged��Ĭ��ֵΪ1,��ɫģʽ
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