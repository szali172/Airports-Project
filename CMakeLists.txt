cmake_minimum_required(VERSION 2.8)

# Set Policies
if(POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif()

if(POLICY CMP0023)
  cmake_policy(SET CMP0023 NEW)
endif()

if(POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif()

##########################################################

# https://stackoverflow.com/questions/43862273/cmake-c-include-relative-to-base-directory
project(Airports VERSION 1.0)

set(CMAKE_BUILD_TYPE Debug)

# add_subdirectory(parsing)
# add_subdirectory(adder)
add_subdirectory(parse-dijkstra)
add_subdirectory(visual-dfs)
add_subdirectory(src)