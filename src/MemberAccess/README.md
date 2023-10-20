## 功能

- 判断类成员变量/函数是否存在
- 判断/获取类成员变量的访问权限

## 函数介绍

```c++
class TestStruct {
public:
    int publicMember;

protected:
    int protectedMember;

private:
    int privateMember;
};
```

- `REGISTER_MEMBER(member)`

注册一个结构体/类成员检查器, 后续函数必须注册对应成员后才可以调用.

例：

```c++
// 注册一个名为publicMember的检查器
- `REGISTER_MEMBER(publicMember)`
```

- `IS_A_MEMBER(type, member)`
    - 判断类型type是否存在名为member的成员变量/函数
    - 返回值类型：bool
    - 适用于：成员变量、成员函数

- `MEMBER_VAR_ACCESS_LEVEL(type, member)`
    - 返回成员变量member在type类型中的可访问等级
    - 返回值类型: MemberAccessLevel
    - 适用于：成员变量

- `IS_PUBLIC_MEMBER_VAR(type, member)`
    - 判断类型type是否存在公有成员变量member
    - 返回值类型：bool
    - 适用于：成员变量

- `IS_PROTECTED_MEMBER_VAR(type, member)`
    - 判断类型type是否存在保护成员变量member
    - 返回值类型：bool
    - 适用于：成员变量

- `IS_PRIVATE_MEMBER_VAR(type, member)`
    - 判断类型type是否存在私有成员变量member
    - 返回值类型：bool
    - 适用于：成员变量
