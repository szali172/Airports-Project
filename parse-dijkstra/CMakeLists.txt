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
add_library(Parse-DijkstraLib ${SOURCES} ${INCLUDES})

# Link
target_include_directories(Parse-DijkstraLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link Parsing Library to the a-star one
# link_directories("../parsing")
# target_link_libraries(Parse-DijkstraLib ParsingLib)

# Add the executable
add_executable(main-parse-dijkstra main.cpp)
target_link_libraries(main-parse-dijkstra Parse-DijkstraLib)

target_include_directories(main-parse-dijkstra PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add Catch2
Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.1
)

FetchContent_MakeAvailable(Catch2)
add_executable(test-parse-dijkstra ${SOURCES} ${TEST_SOURCES})
target_link_libraries(test-parse-dijkstra Parse-DijkstraLib Catch2::Catch2)