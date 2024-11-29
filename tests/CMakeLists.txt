include(CTest)

set(TESTER "tester")


add_executable("${TESTER}"
  ./test-main.cpp
)
target_link_libraries("${TESTER}" PRIVATE "${UTILLIB}")

add_test(NAME "${TESTER}" COMMAND "${TESTER}")
