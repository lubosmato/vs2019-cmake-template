#include <iostream>
#include <boost/asio.hpp>
#include "huge_library/greeting.hpp"
#include "dll_library/greeting.hpp"

void my_task()
{
	std::cout << "Hello there\n";
}

int main()
{
	library_func();
	dll_func();

	boost::asio::io_context io_context;
	boost::asio::post(io_context, my_task);
	boost::asio::post(io_context, []() {
		std::cout << "What is doing this?\n";
		});

	// Run the io_context until it runs out of work.
	io_context.run();

	return 0;
}
