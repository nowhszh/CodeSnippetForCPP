//
// Created by marvin on 23-10-19.
//

#pragma once

#include <type_traits>

// code build require >= c++14

// The current code can determine at compile time whether the class contains the specified member.

// Before use, you need to use the macro REGISTER_MEMBER(member) to generate the corresponding member detection class,
// and then you can use the macro function to judge the result.
// the following are some of the available macro functions:

// Determine if "member" is a member/member function of "type".
#define IS_A_MEMBER(type, member) (__##member##MemberAccess<type>::is_existed)

// Get the accessibility of "member" in class "type", return type is MemberAccessLevel.
#define MEMBER_VAR_ACCESS_LEVEL(type, member) (__##member##MemberAccess<type>::access_level)

// Checks if the accessibility of "member" in class "type" is public/protected/private.
#define IS_PUBLIC_MEMBER_VAR(type, member)    (__##member##MemberAccess<type>::is_public_member)
#define IS_PROTECTED_MEMBER_VAR(type, member) (__##member##MemberAccess<type>::is_protected_member)
#define IS_PRIVATE_MEMBER_VAR(type, member)   (__##member##MemberAccess<type>::is_private_member)

enum class MemberAccessLevel {
    NO_MEMBER,
    PUBLIC,
    PROTECTED,
    PRIVATE,
};

#define REGISTER_MEMBER(member)                                                                                        \
    template <typename T> class __##member##MemberAccess {                                                             \
    private:                                                                                                           \
        template <typename U = T> static constexpr bool accessible(decltype(std::declval<U>().member)*)                \
        {                                                                                                              \
            return true;                                                                                               \
        }                                                                                                              \
        template <typename U = T> static constexpr bool accessible(...) { return false; }                              \
                                                                                                                       \
        struct Derived : T {                                                                                           \
            template <typename U = Derived> static constexpr bool accessible(decltype(std::declval<U>().member)*)      \
            {                                                                                                          \
                return true;                                                                                           \
            }                                                                                                          \
            template <typename U = Derived> static constexpr bool accessible(...) { return false; }                    \
        };                                                                                                             \
                                                                                                                       \
        struct Conflict {                                                                                              \
            int member;                                                                                                \
        };                                                                                                             \
        struct CheckExist : T, Conflict {                                                                              \
            template <typename U = CheckExist> static constexpr bool existed(decltype(std::declval<U>().member)*)      \
            {                                                                                                          \
                return false;                                                                                          \
            }                                                                                                          \
                                                                                                                       \
            template <typename U = CheckExist> static constexpr bool existed(...) { return true; }                     \
        };                                                                                                             \
                                                                                                                       \
        static constexpr MemberAccessLevel level()                                                                     \
        {                                                                                                              \
            /* This function requires >=c++14, if used? : instead of it, c++11 is fine */                              \
            if (accessible(nullptr)) {                                                                                 \
                return MemberAccessLevel::PUBLIC;                                                                      \
            } else if (Derived::accessible(nullptr)) {                                                                 \
                return MemberAccessLevel::PROTECTED;                                                                   \
            } else if (CheckExist::existed(nullptr)) {                                                                 \
                return MemberAccessLevel::PRIVATE;                                                                     \
            } else {                                                                                                   \
                return MemberAccessLevel::NO_MEMBER;                                                                   \
            }                                                                                                          \
        }                                                                                                              \
                                                                                                                       \
    public:                                                                                                            \
        static constexpr bool is_public_member    = accessible(nullptr);                                               \
        static constexpr bool is_protected_member = Derived::accessible(nullptr) && !accessible(nullptr);              \
        static constexpr bool is_private_member                                                                        \
            = CheckExist::existed(nullptr) && !accessible(nullptr) && !Derived::accessible(nullptr);                   \
        static constexpr bool              is_existed   = CheckExist::existed(nullptr);                                \
        static constexpr MemberAccessLevel access_level = level();                                                     \
    };
