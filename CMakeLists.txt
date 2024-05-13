cmake_minimum_required(VERSION 3.10)
project(Astar)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#注意调用顺序，A被B所调用，则A需要在B前进行先编译
set(SRC_FILE
    src/Node.cpp
    src/main.cpp
    src/myAstar.cpp)

set(CMAKE_BUILD_TYPE "DEBUG")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
add_executable(Astar ${SRC_FILE})

add_library(Astar_so SHARED ${SRC_FILE} ${INC_FILE})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)



