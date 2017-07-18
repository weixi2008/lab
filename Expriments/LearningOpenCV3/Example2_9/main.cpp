#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//ת����ɫ��������ȡ����Canny���Ӻ�ȡ�ö�Ӧλ�õ����ء�
//ע�⣺coutʱ����Ҫ��ucharתΪuint
//ע�⣺at�������ݵģ�y��x��,yָheight���� xָwidth�����е㷴���ࡣ
int main(int argc, char** argv) {
	Mat img = imread("C:\\Users\\weixi\\Pictures\\lena.bmp", CV_LOAD_IMAGE_UNCHANGED);
	if (img.empty()) return -1;
	
	Mat img_gry, img_pyr, img_pyr2, img_cny;

	cvtColor(img, img_gry, CV_BGR2GRAY);
	pyrDown(img_gry, img_pyr);
	pyrDown(img_pyr, img_pyr2);
	Canny(img_pyr2, img_cny, 10, 100, 3, true);

	int x = 16, y = 32;
	cv::Vec3b intensity = img.at<cv::Vec3b>(y, x);
	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	cout << "At (x, y) = (" << x << " , " << y
		<< "): (blue, green, red) = ( " << (unsigned int)blue << ", " << (unsigned int)green << ", " << (unsigned int)red << ")" << endl;

	cout << "Gray pixel there is: " << (unsigned int)img_gry.at<uchar>(y, x) << endl;

	x /= 4;
	y /= 4;
	cout << "Pyramid2 pixel there is: " << (unsigned int)img_pyr2.at<uchar>(y, x) << endl;

	img_cny.at<uchar>(x, y) = 128;

	return 0;

}