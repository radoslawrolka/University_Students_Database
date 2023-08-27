cmake_minimum_required(VERSION 3.26)
project(University_Students_Database)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(University_Students_Database
        src/main.cpp
        src/Database.cpp
        src/Student.cpp
        src/UserClient.cpp
        src/UserClient.h
        src/AdminClient.cpp
        src/AdminClient.h)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        USD_unittest
        src/test.cpp
        src/Database.cpp
        src/Student.cpp
        src/UserClient.cpp
        src/UserClient.h
        src/AdminClient.cpp
        src/AdminClient.h
)
target_link_libraries(
        USD_unittest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(USD_unittest)