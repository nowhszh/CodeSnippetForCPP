//
// Created by marvin on 23-10-20.
//
#include <iostream>

#include "test_common.h"

REGISTER_MEMBER(noMember)

int main()
{
    constexpr Result true_result { false, false, false, false, MemberAccessLevel::NO_MEMBER };
    constexpr Result run_result {
        .exist  = IS_A_MEMBER(TestStruct, noMember),
        .isPub  = IS_PUBLIC_MEMBER_VAR(TestStruct, noMember),
        .isProt = IS_PROTECTED_MEMBER_VAR(TestStruct, noMember),
        .isPri  = IS_PRIVATE_MEMBER_VAR(TestStruct, noMember),
        .level  = MEMBER_VAR_ACCESS_LEVEL(TestStruct, noMember),
    };

    return test_output("noMember", true_result, run_result);
}
