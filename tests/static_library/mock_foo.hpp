#include <gmock/gmock.h>

#include "static_library/greeting.hpp"

struct MockFoo : Foo {
    MOCK_CONST_METHOD0(answerToUltimateQuestion, int());
};
