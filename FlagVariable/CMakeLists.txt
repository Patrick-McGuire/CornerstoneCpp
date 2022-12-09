cmake_minimum_required(VERSION 3.17)
project(FlagVariable)

set(CMAKE_CXX_STANDARD 17)

add_executable(FlagVariable main.cpp FlagVariable.h ConfigVariable.h)