include(CTest)


# History
add_executable(history
  ./test-history.cpp
)
target_link_libraries(history PRIVATE "${UTILLIB}")
add_test(NAME test-history COMMAND history)


# Match
add_executable(match
  ./test-match.cpp
)
target_link_libraries(match PRIVATE "${UTILLIB}")
add_test(NAME test-match COMMAND match)


# Recommend
add_executable(recommend
  ./test-recommend.cpp
)
target_link_libraries(recommend PRIVATE "${UTILLIB}")
add_test(NAME test-recommend COMMAND recommend)
