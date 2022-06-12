include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(GameSession-test GameSession-test.cpp)

target_link_libraries(GameSession-test 
	PRIVATE
		GTest::GTest
		GameSession_lib)

add_test(Mastermind_gtests GameSession-test)