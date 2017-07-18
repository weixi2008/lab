#include <opencv2/opencv.hpp>

using namespace cv;
const char EXAMPLE_WINDOW_IN[] = "Example2_5-in";
const char EXAMPLE_WINDOW_OUT[] = "Example2_5-out";

int main(int argc, char** argv) {
	//CV_LOAD_IMAGE_UNCHANGED
	Mat img = imread("C:\\Users\\weixi\\Pictures\\lena.bmp", CV_LOAD_IMAGE_UNCHANGED);
	if (img.empty()) return -1;

	namedWindow(EXAMPLE_WINDOW_IN, cv::WINDOW_AUTOSIZE);
	namedWindow(EXAMPLE_WINDOW_OUT, cv::WINDOW_AUTOSIZE);

	imshow(EXAMPLE_WINDOW_IN, img);

	Mat imgout;
	//双重模糊
	//高斯核的Size必须设置为奇数，因为计算的结果写入中心像素
	GaussianBlur(img, imgout, Size(5, 5), 3, 3);
	GaussianBlur(imgout, imgout, Size(5, 5), 3, 3);
	imshow(EXAMPLE_WINDOW_OUT, imgout);


	waitKey(0);
}