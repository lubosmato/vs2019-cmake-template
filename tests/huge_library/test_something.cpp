#include <gtest/gtest.h>
#include <string>

#include "huge_library/greeting.hpp"
#include "mock_foo.hpp"

using namespace testing;

TEST(MyTest, foobar) {
    library_func();
    std::string foo("foobar");
    std::string bar("foobar");
    ASSERT_STREQ(foo.c_str(), bar.c_str());
    EXPECT_FALSE(false);
}

TEST(MyTest, mocking) {
    Foo foo;
    MockFoo mockFoo;
    EXPECT_CALL(mockFoo, answerToUltimateQuestion()).WillOnce(Return(58));

    ASSERT_EQ(mockFoo.answerToUltimateQuestion(), 58);
    ASSERT_EQ(foo.answerToUltimateQuestion(), 42);
}
