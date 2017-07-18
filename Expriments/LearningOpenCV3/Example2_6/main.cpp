#include <opencv2/opencv.hpp>

using namespace cv;
const char EXAMPLE_WINDOW1[] = "Example1";
const char EXAMPLE_WINDOW2[] = "Example2";

//����pyDown������һ����߼����ͼ��
int main(int argc, char** argv) {
	//��2������flag�� ����ָ��ͼƬ����ɫģʽ�� -1Ϊunchanged��Ĭ��ֵΪ1,��ɫģʽ
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