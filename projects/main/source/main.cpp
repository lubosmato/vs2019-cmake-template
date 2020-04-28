#include <iostream>

#include <boost/asio.hpp>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <static_library/greeting.hpp>
#include <dll_library/greeting.hpp>
#include <static_external_library/library.hpp>
#include <qt_gui/gui.hpp>

#include "main/greeter.hpp"

void my_task()
{
	std::string_view test = "Hello I am a task running in Boost ASIO\n";
	std::cout << test;
}

int main()
{
	library_func();
	dll_func();
	hello();
	greet();

	cv::Mat image = cv::Mat(256, 256, CV_8UC3, cv::Scalar{ 0 });

	boost::asio::io_context io_context;
	boost::asio::post(io_context, my_task);
	boost::asio::post(
		io_context, 
		[&image]() {
			std::cout << "Hello I am another task?\n";
			cv::line(image, { 0, 0 }, { 255, 255 }, { 80, 160, 240 });
		}
	);
	io_context.run();

	cv::imshow("Image", image);
	cv::waitKey();
	cv::destroyAllWindows();

	show_window();

	return 0;
}
