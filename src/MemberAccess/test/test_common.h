//
// Created by marvin on 23-10-20.
//

#pragma once

#include <string>

#include "MemberAccess.hpp"

class TestStruct {
public:
    int publicMember;


protected:
    int protectedMember;

private:
    int privateMember;
    void hello() { }
};

struct Result {
    bool              exist;
    bool              isPub;
    bool              isProt;
    bool              isPri;
    MemberAccessLevel level;
};

constexpr const char*                       bool_str(bool b) { return b ? "true" : "false"; }
constexpr int                               bool_int(bool b) { return b ? 1 : 0; }
template <typename T> constexpr const char* color(T&& a, T&& b) { return (a == b) ? "\033[32m" : "\033[31m"; }

int test_output(const std::string& memberName, const Result trueResult, const Result runResult)
{
    int ret = 0;

    ret += bool_int(trueResult.exist != runResult.exist);
    printf("%s is a member of TestStruct: %s%s\033[0m\n", memberName.c_str(), color(trueResult.exist, runResult.exist),
        bool_str(runResult.exist));

    ret += bool_int(trueResult.isPub != runResult.isPub);
    printf("%s is a public member of TestStruct: %s%s\033[0m\n", memberName.c_str(),
        color(trueResult.isPub, runResult.isPub), bool_str(runResult.isPub));

    ret += bool_int(trueResult.isProt != runResult.isProt);
    printf("%s is a protected member of TestStruct: %s%s\033[0m\n", memberName.c_str(),
        color(trueResult.isProt, runResult.isProt), bool_str(runResult.isProt));

    ret += bool_int(trueResult.isPri != runResult.isPri);
    printf("%s is a private member of TestStruct: %s%s\033[0m\n", memberName.c_str(),
        color(trueResult.isPri, runResult.isPri), bool_str(runResult.isPri));

    ret += bool_int(trueResult.level != runResult.level);
    printf("%s access level: %s%d\033[0m\n", memberName.c_str(), color(trueResult.level, runResult.level),
        (int)runResult.level);

    return -ret;
}
