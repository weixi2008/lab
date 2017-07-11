#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

const char EXAMPLE_WINDOW[] = "Example2_3";

int main(int argc, char** argv) {
	namedWindow(EXAMPLE_WINDOW, cv::WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open("C:\\Users\\weixi\\Pictures\\MachineLearningIntroduction.mp4");

	Mat frame;
	for (;;) {
		cap >> frame;
		if (frame.empty()) break;
		imshow(EXAMPLE_WINDOW, frame);
		int userkey = waitKey(33);
		cout << userkey << endl;
		//在3.2.0的版本上有Bug，在无外部按键下，会返回255，从而使下述语句break
		//if (waitKey(33) >= 0) break;
	}
	
	destroyWindow(EXAMPLE_WINDOW);
	return 0;
}