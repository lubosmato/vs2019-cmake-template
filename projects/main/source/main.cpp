#include <iostream>
#include <boost/asio.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "huge_library/greeting.hpp"
#include "dll_library/greeting.hpp"
#include "external_library/library.hpp"

void my_task()
{
	std::cout << "Hello there\n";
}

int main()
{
	library_func();
	dll_func();
	hello();

	boost::asio::io_context io_context;
	boost::asio::post(io_context, my_task);
	boost::asio::post(
		io_context, 
		[]() {
			std::cout << "What is doing this?\n";
		}
	);
	io_context.run();

	cv::Mat image = cv::Mat(256, 256, CV_8UC3, cv::Scalar{ 0 });
	cv::line(image, { 0, 0 }, { 255, 255 }, { 80, 160, 240 });
	cv::imshow("Image", image);
	cv::waitKey();
	cv::destroyAllWindows();

	return 0;
}
