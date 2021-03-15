#include <iostream>
#include <compare>
#include <experimental/generator>

#include <boost/asio.hpp>

// #include <opencv2/core.hpp>
// #include <opencv2/imgproc.hpp>
// #include <opencv2/highgui.hpp>

#include <static_library/greeting.hpp>
#include <dll_library/greeting.hpp>
#include <static_external_library/library.hpp>
#include <qt_gui/gui.hpp>

#include "main/greeter.hpp"

using namespace std::experimental;

// This concept tests whether 'T::type' is a valid type
template <typename T>
concept has_type_member = requires { typename T::type; };

struct S1
{
};

struct S2
{
    using type = int;
};

static_assert(!has_type_member<S1>);
static_assert(has_type_member<S2>);

void my_task()
{
    std::string_view test = "Hello I am a task running in Boost ASIO\n";
    std::cout << test;
}

void spaceship()
{
    auto [a, b] = std::make_tuple(10.0, 20.0);
    const bool spaceship = (a <=> b) > 0;
    std::cout << "Spaceship result: " << spaceship << std::endl;
}

void designated_init()
{
    struct A
    {
        int x;
        int y;
        int z;
    };
    const A b{.x = 1, .z = 2}; // b.y == 0

    std::cout << "x: " << b.x << ", y: " << b.y << ", z: " << b.z << std::endl;
}

generator<int> sequence(int begin, int step = 1) noexcept
{
    for (int i = begin; true; i += step)
    {
        co_yield i;
    }
}

void coroutines()
{
    for (auto n : sequence(0, 5))
    {
        if (n > 50) break;
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    spaceship();
    designated_init();
    coroutines();

    library_func();
    dll_func();
    hello();
    greet();

    // cv::Mat image = cv::Mat(256, 256, CV_8UC3, cv::Scalar{0});
    boost::asio::io_context io_context;
    boost::asio::post(io_context, my_task);
    boost::asio::post(
        io_context,
        [/*&image*/]()
        {
            std::cout << "Hello I am another task?\n";
            // cv::line(image, {0, 0}, {255, 255}, {80, 160, 240});
        }
    );
    io_context.run();

    // cv::imshow("Image", image);
    // cv::waitKey();
    // cv::destroyAllWindows();

    show_window();

    return 0;
}
