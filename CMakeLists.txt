cmake_minimum_required(VERSION 3.13)
project(webTest)
if (POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif ()
set (CMAKE_CXX_STANDARD 11)
#set(EXECUTABLE_OUTPUT_PATH ~/code/bad)

#The includes
include_directories(include)

file(GLOB SOURCES src/*.cpp)

#remove from glob
#list(REMOVE_ITEM SOURCES simplang/badcode.cpp)

add_executable(webTest ${SOURCES})
target_link_libraries(webTest curl)