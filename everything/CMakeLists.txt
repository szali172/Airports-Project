cmake_minimum_required(VERSION 3.1)

# Specify the C++ standard (CMake3+)
add_compile_options(-std=c++11)

# Add header files
file(GLOB INCLUDES "includes/*.h")

# Add src files
file(GLOB SOURCES "src/*.cpp")

# Add testing sources
file(GLOB TEST_SOURCES "tests/*.cpp")

# Add library interface for our files
add_library(EverythingLib ${SOURCES} ${INCLUDES})

# Link
target_include_directories(EverythingLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "../parsing/include")

# Link Parsing Library to the a-star one
link_directories("../parsing")
target_link_libraries(EverythingLib ParsingLib)

# Add the executable
add_executable(main-everything main.cpp)
target_link_libraries(main-everything EverythingLib)

target_include_directories(main-everything PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add Catch2
Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.1
)

FetchContent_MakeAvailable(Catch2)
add_executable(test-everything ${SOURCES} ${TEST_SOURCES})
target_link_libraries(test-everything EverythingLib Catch2::Catch2)