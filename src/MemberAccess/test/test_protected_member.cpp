//
// Created by marvin on 23-10-20.
//
#include <iostream>

#include "test_common.h"

REGISTER_MEMBER(protectedMember)

int main()
{
    constexpr Result true_result { true, false, true, false, MemberAccessLevel::PROTECTED };
    constexpr Result run_result {
        .exist  = IS_A_MEMBER(TestStruct, protectedMember),
        .isPub  = IS_PUBLIC_MEMBER_VAR(TestStruct, protectedMember),
        .isProt = IS_PROTECTED_MEMBER_VAR(TestStruct, protectedMember),
        .isPri  = IS_PRIVATE_MEMBER_VAR(TestStruct, protectedMember),
        .level  = MEMBER_VAR_ACCESS_LEVEL(TestStruct, protectedMember),
    };

    return test_output("protectedMember", true_result, run_result);
}