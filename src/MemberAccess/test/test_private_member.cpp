//
// Created by marvin on 23-10-20.
//
#include <iostream>

#include "test_common.h"

REGISTER_MEMBER(privateMember)

int main()
{
    constexpr Result true_result { true, false, false, true, MemberAccessLevel::PRIVATE };
    constexpr Result run_result {
        .exist  = IS_A_MEMBER(TestStruct, privateMember),
        .isPub  = IS_PUBLIC_MEMBER(TestStruct, privateMember),
        .isProt = IS_PROTECTED_MEMBER(TestStruct, privateMember),
        .isPri  = IS_PRIVATE_MEMBER(TestStruct, privateMember),
        .level  = MEMBER_ACCESS_LEVEL(TestStruct, privateMember),
    };

    return test_output("privateMember", true_result, run_result);
}