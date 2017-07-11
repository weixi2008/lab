#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

const char EXAMPLE_WINDOW[] = "Example2_4";
const char EXAMPLE_TRACKBAR[] = "Position";


int g_slider_position = 0;
// 1 为一帧一帧播放。 0 为停止。 负数为连续播放。
int g_run = 1;
//当视频自动播放时，会调用setTracbarPos设置进度条。g_dontset=1,此时不会重置g_run。而仅仅会更新trackbar的位置。
int g_dontset = 0;
VideoCapture g_cap;

void OnTrackbarSlide(int pos, void*) {
	g_cap.set(CAP_PROP_POS_FRAMES, pos);
	if (!g_dontset) {
		g_run = 1;
	}
	g_dontset = 0;
}

int main(int argc, char** argv) {
	namedWindow(EXAMPLE_WINDOW, cv::WINDOW_AUTOSIZE);
	g_cap.open("C:\\Users\\weixi\\Pictures\\MachineLearningIntroduction.mp4");
	int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);
	cout << "Video has " << frames << " frames of dimensions( "
		<< tmpw << " , " << tmph << ")." << endl;

	createTrackbar(EXAMPLE_TRACKBAR, EXAMPLE_WINDOW, &g_slider_position, frames, OnTrackbarSlide);

	Mat frame;
	for (;;) {
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty()) break;
			int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
			g_dontset = 1;
			setTrackbarPos(EXAMPLE_TRACKBAR, EXAMPLE_WINDOW, current_pos);
			imshow(EXAMPLE_WINDOW, frame);
			g_run -= 1;
		}
		char c = (char)cv::waitKey(10);
		if (c == 's') {
			g_run = 1;
			cout << "Single Step. run = " << g_run << endl;
		}
		else if (c == 'r') {
			g_run = -1;
			cout << "Run mode. run = " << g_run << endl;
		}
		else if (c == 27) {//ESC
			break;
		}
	}

	destroyWindow(EXAMPLE_WINDOW);
	return 0;
}