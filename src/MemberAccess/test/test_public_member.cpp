//
// Created by marvin on 23-10-20.
//
#include <iostream>

#include "test_common.h"

REGISTER_MEMBER(publicMember)

int main()
{
    constexpr Result true_result { true, true, false, false, MemberAccessLevel::PUBLIC };
    constexpr Result run_result {
        .exist  = IS_A_MEMBER(TestStruct, publicMember),
        .isPub  = IS_PUBLIC_MEMBER(TestStruct, publicMember),
        .isProt = IS_PROTECTED_MEMBER(TestStruct, publicMember),
        .isPri  = IS_PRIVATE_MEMBER(TestStruct, publicMember),
        .level  = MEMBER_ACCESS_LEVEL(TestStruct, publicMember),
    };

    return test_output("publicMember", true_result, run_result);
}