cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Time_Proj VERSION 0.4 LANGUAGES CXX)
set(CMAKE_CXX STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
 googletest
 URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
 # SOURCE_DIR "<path_to>/googletest-main"
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

option(ENABLE_TEST "Enable tests geeration" ON)
if (ENABLE_TEST)
 enable_testing()
endif()

add_library(my_time STATIC Time.h Time.cpp)

if (ENABLE_TEST)
 add_executable(my_time_test TimeTest.cpp)
endif()

target_link_libraries(my_time_test GTest::gtest_main my_time)

include(GoogleTest)
gtest_discover_tests(my_time_test)



