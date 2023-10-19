

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_test_bin(no_member)
add_test_bin(public_member)
add_test_bin(protected_member)
add_test_bin(private_member)
