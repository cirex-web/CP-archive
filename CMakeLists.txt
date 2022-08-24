cmake_minimum_required(VERSION 3.22)
project(UCF)

#set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
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



add_executable(C 1715/C.cpp)
add_executable(G 103091/G.cpp)
add_executable(A 1715/A.cpp)
add_executable(E 1712/E.cpp)
add_executable(F 103091/F.cpp)
add_executable(H 103091/H.cpp)
add_executable(K 103091/K.cpp)
add_executable(L 103091/L.cpp)
add_executable(N 103091/N.cpp)

add_executable(D 1715/D.cpp)
add_executable(J 103091/J.cpp)
add_executable(I 103091/I.cpp)


add_executable(671A CF/671A.cpp)
add_executable(280A CF/280A.cpp)

add_executable(where 1713/where.cpp)

add_executable(B 1715/B.cpp)
add_executable(C2 103091/C2.cpp)
add_executable(1354C2 CF/1354C2.cpp)
add_executable(1716A CF/1716A.cpp)
add_executable(1370B CF/1370B.cpp)
add_executable(1263C CF/1263C.cpp)
add_executable(1033B CF/1033B.cpp)
add_executable(1119A CF/1119A.cpp)
add_executable(1579B CF/1579B.cpp)
add_executable(1038B CF/1038B.cpp)
add_executable(1038B_2 CF/1038B_2.cpp)

add_executable(1430E CF/1430E.cpp)
add_executable(533B CF/533B.cpp)
add_executable(1530E CF/1530E.cpp)

add_executable(1599C CF/1599C.cpp)
add_executable(1599C2 CF/1599C2.cpp)
add_executable(1654D CF/1654D.cpp)

add_executable(1451A CF/1451A.cpp)
add_executable(843B CF/843B.cpp)
add_executable(1472D CF/1472D.cpp)

add_executable(Dslow 1715/Dslow.cpp)
add_executable(1618B CF/1618B.cpp)
add_executable(260A CF/260A.cpp)
add_executable(1656D CF/1656D.cpp)
add_executable(5C CF/5C.cpp)
add_executable(5C2 CF/5C2.cpp)
add_executable(1470B CF/1470B.cpp)
add_executable(259A CF/259A.cpp)
add_executable(1285D CF/1285D.cpp)
add_executable(1220D CF/1220D.cpp)
add_executable(1066E CF/1066E.cpp)