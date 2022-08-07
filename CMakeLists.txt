cmake_minimum_required(VERSION 3.22)
project(UCF)

#set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-std=c++17 -include-pch /Users/work/Documents/C++2/stdc++.h.gch -O2 -Wall")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

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



add_executable(C 1713/C.cpp)
add_executable(G 103091/G.cpp)
add_executable(B 1713/B.cpp)
add_executable(A 1713/A.cpp)
add_executable(E 1713/E.cpp)
add_executable(F 103091/F.cpp)
add_executable(H 103091/H.cpp)
add_executable(K 103091/K.cpp)
add_executable(L 103091/L.cpp)
add_executable(N 103091/N.cpp)

add_executable(D 1713/D.cpp)
add_executable(J 103091/J.cpp)
add_executable(I 103091/I.cpp)


add_executable(671A CF/671A.cpp)
add_executable(280A CF/280A.cpp)

add_executable(where 1713/where.cpp)
add_executable(dfs 1706/dfs.cpp)