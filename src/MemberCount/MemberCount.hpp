//
// Created by marvin on 23-10-20.
//

#pragma once

#include <cinttypes>
#include <type_traits>

// code build require >= c++20

namespace snippet {

template <typename T> class MemberCount {
private:
    struct AnyType {
        template <typename TC>
            requires(!std::is_same<std::remove_cv<TC>, std::remove_cv<T>>::value)
        operator TC();
    };

    // version 1
    template <typename U> static constexpr auto calc(auto&&... args)
    {
        if constexpr (!requires { U { args... }; }) {
            return sizeof...(args) - 1;
        } else {
            return calc<U>(args..., AnyType {});
        }
    }

    // version 2
    template <typename U, typename... Args> constexpr std::size_t calc2(Args&&... args)
    {
        if constexpr (!requires { U { args... }; }) {
            return sizeof...(args) - 1;
        } else {
            return calc2<U>(args..., AnyType {});
        }
    }

public:
    static constexpr std::size_t value = calc<T>();
};

}
