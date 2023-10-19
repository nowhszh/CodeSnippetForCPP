//
// Created by marvin on 23-10-20.
//

#include "MemberCount.hpp"

#include <string>

template <typename T> const char* color(T a, const T b, auto cmp) { return (cmp(a, b)) ? "\033[32m" : "\033[31m"; }

int test_output(const char* name, bool is_equal, std::size_t expect_cnt, std::size_t cnt)
{
    const char* SGR = is_equal ? color(expect_cnt, cnt, std::equal_to<std::size_t> {})
                               : color(expect_cnt, cnt, std::not_equal_to<std::size_t> {});

    printf("%s member count, %s%s\033[0m number expected, expected: %zu,actual %zu\n", name, SGR,
        (is_equal ? "equal" : "unequal"), expect_cnt, cnt);
    return (cnt == expect_cnt) == is_equal ? 0 : -1;
}

struct TestStruct {
    std::string name;
    int         num1;
    int         num2;
};

struct TestEmpty { };

struct TestHasPrivate {
    int num1;
    int num2;

private:
    int num3;
};

int main()
{
    int ret = 0;

    using snippet::MemberCount;

    ret += test_output("TestStruct", true, 3, MemberCount<TestStruct>::value);
    ret += test_output("TestEmpty", true, 0, MemberCount<TestEmpty>::value);
    ret += test_output("TestHasPrivate", false, 2, MemberCount<TestHasPrivate>::value);

    return ret;
}