## 功能

编译期获取结构体或无私有/保护数据的类成员数量

## 介绍

- `template <typename T> class MemberCount<T>`
  - 例
    ```c++
    #include <MemberCount.hpp>
    #include <ctime>
    
    auto count = snippet::MemberCount<tm>::value;
    ```


