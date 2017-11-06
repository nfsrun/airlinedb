cmake_minimum_required(VERSION 3.8)
project(airlinedb)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES LinkedList.h OrderedLinkedList.h Launcher.cpp Passenger.h Validator.h)
add_executable(airlinedb ${SOURCE_FILES})