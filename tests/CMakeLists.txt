include(CTest)

add_executable(test-weigh
  ./test-weigh.cpp
)
target_link_libraries(test-weigh PRIVATE "${UTILLIB}")

add_test(NAME test-weigh COMMAND test-weigh)
