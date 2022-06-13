enable_testing()

include(FetchContent)

include_directories(${CMAKE_SOURCE_DIR}/source/include)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(Mastermind-tests "Code-test.cpp" "Arbiter-test.cpp")
target_include_directories(Mastermind-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})
target_link_libraries(Mastermind-tests PRIVATE GTest::GTest Mastermind_lib)

add_test(Mastermind_gtests Mastermind-tests)