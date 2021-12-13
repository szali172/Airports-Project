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
add_library(Visual-DFSLib ${SOURCES} ${INCLUDES})

# Link
target_include_directories(Visual-DFSLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "../parse-dijkstra/include")

# Link Parsing Library to the a-star one
link_directories("../parse-dijkstra")
target_link_libraries(Visual-DFSLib Parse-DijkstraLib)

# Add the executable
add_executable(main-visual-dfs main.cpp)
target_link_libraries(main-visual-dfs Visual-DFSLib)

target_include_directories(main-visual-dfs PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add Catch2
Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.1
)

FetchContent_MakeAvailable(Catch2)
add_executable(test-visual-dfs ${SOURCES} ${TEST_SOURCES})
target_link_libraries(test-visual-dfs Visual-DFSLib Catch2::Catch2)