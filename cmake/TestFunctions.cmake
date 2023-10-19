
function(add_test_bin test_name)
    add_executable(${test_name} ./test/test_${test_name}.cpp)
    add_test(NAME test_${test_name} COMMAND ./${test_name})
endfunction()

