#ifndef HUGE_LIBRARY_HPP_
#define HUGE_LIBRARY_HPP_

struct Foo {
    virtual ~Foo() = default;
    virtual int answerToUltimateQuestion() const;
};

void library_func();

#endif // HUGE_LIBRARY_HPP_
