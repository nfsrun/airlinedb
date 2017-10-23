cmake_minimum_required(VERSION 3.8)
project(Airline_Tracker)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Launcher.cpp LinkedList.h OrderedLinkedList.cpp OrderedLinkedList.h)
add_executable(Airline_Tracker ${SOURCE_FILES})