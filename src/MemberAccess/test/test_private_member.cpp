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
        .isPub  = IS_PUBLIC_MEMBER_VAR(TestStruct, privateMember),
        .isProt = IS_PROTECTED_MEMBER_VAR(TestStruct, privateMember),
        .isPri  = IS_PRIVATE_MEMBER_VAR(TestStruct, privateMember),
        .level  = MEMBER_VAR_ACCESS_LEVEL(TestStruct, privateMember),
    };

    return test_output("privateMember", true_result, run_result);
}