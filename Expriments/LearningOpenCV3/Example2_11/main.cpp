#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
const char EXAMPLE_WINDOW[] = "Example";
const char LOGPOLAR_WINDOW[] = "LogPolar";


//从摄像头获得视频，LogPolar变换后，存储在硬盘上
int main(int argc, char** argv) {

	namedWindow(EXAMPLE_WINDOW, cv::WINDOW_AUTOSIZE);
	namedWindow(LOGPOLAR_WINDOW, cv::WINDOW_AUTOSIZE);

	cv::VideoCapture capture;
	capture.open(0);
	if (!capture.isOpened()) {
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}
	

	double fps = capture.get(cv::CAP_PROP_FPS);
	cv::Size size((int)capture.get(cv::CAP_PROP_FRAME_WIDTH), (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT));

	cv::VideoWriter writer;
	writer.open("C:\\Users\\weixi\\Pictures\\capture.mjpg", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
	if (!writer.isOpened()) {
		std::cerr << "Couldn't open writer." << std::endl;
		return -1;
	}

	cv::Mat logpolar_frame, bgr_frame;

	for (;;) {
		capture >> bgr_frame;
		if (bgr_frame.empty()) break;

		cv::imshow(EXAMPLE_WINDOW, bgr_frame);

		cv::Point2f center(bgr_frame.cols / 2, bgr_frame.rows / 2);
		cv::logPolar(bgr_frame, logpolar_frame, center, 40, cv::WARP_FILL_OUTLIERS);

		cv::imshow(LOGPOLAR_WINDOW, logpolar_frame);
		writer << logpolar_frame;

		char c = (char)cv::waitKey(10);
		if (c == 27) break; //ESC
	}

	capture.release();
	return 0;

	//destroyWindow(EXAMPLE_WINDOW);
}