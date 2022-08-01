cmake_minimum_required(VERSION 3.22)
project(UCF)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS "-include-pch /Users/work/Documents/C++2/stdc++.h.gch -O2 -Wall -Wl -stack_size -Wl,0x10000000000")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include_directories(.)
include_directories(1706)
include_directories(C3)
include_directories(C4)
include_directories(C5)
include_directories(practice)

add_executable(discard "UCF Archives/discard.cpp")
add_executable(elbow "UCF Archives/elbow.cpp")
add_executable(excellence "UCF Archives/excellence.cpp")
add_executable(geography "UCF Archives/geography.cpp")
add_executable(knight "UCF Archives/knight.cpp")

add_executable(treerotations practice/treerotations.cpp)
add_executable(cookie "UCF Archives/cookie.cpp")



add_executable(cactus practice/cactus.cpp)


add_executable(103109A "Random CF/103109A.cpp")

add_executable(foerst practice/foerst.cpp)




add_executable(discord practice/discord.cpp)

add_executable(sleepy practice/sleepy.cpp)
add_executable(longestlife practice/longestlife.cpp)
add_executable(comedyshow practice/comedyshow.cpp)
add_executable(uncertainty practice/uncertainty-data/uncertainty.cpp)
add_executable(raffle practice/raffle.cpp)
add_executable(median practice/median.cpp)


