#include <opencv2/opencv.hpp>

using namespace cv;
const char EXAMPLE_WINDOW[] = "Example2_1";

int main(int argc, char** argv) {
	//第2个参数flag， 可以指定图片的颜色模式。 -1为unchanged，默认值为1,彩色模式
	//Mat img = imread(argv[1], -1);
	Mat img = imread("C:\\Users\\weixi\\Pictures\\S3M1.jpg", CV_LOAD_IMAGE_UNCHANGED);
	if (img.empty()) return -1;

	namedWindow(EXAMPLE_WINDOW, cv::WINDOW_AUTOSIZE);
	imshow(EXAMPLE_WINDOW, img);
	waitKey(0);

	destroyWindow(EXAMPLE_WINDOW);
}