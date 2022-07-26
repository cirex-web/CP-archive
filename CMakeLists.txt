cmake_minimum_required(VERSION 3.22)
project(UCF)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(1706)
include_directories(C3)
include_directories(C4)
include_directories(C5)
include_directories(practice)

add_executable(discard discard.cpp)
add_executable(elbow elbow.cpp)
add_executable(excellence excellence.cpp)
add_executable(geography geography.cpp)
add_executable(knight knight.cpp)

add_executable(treerotations practice/treerotations.cpp)
add_executable(cookie cookie.cpp)