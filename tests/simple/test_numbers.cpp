#include <gtest/gtest.h>
#include <string>

TEST(MyTest2, numbers) {
    ASSERT_EQ(42, 41);
    EXPECT_FALSE(false);
}

TEST(MyTest2, doubles) {
    ASSERT_EQ(42.42, 42.42);
    EXPECT_FALSE(false);
}
