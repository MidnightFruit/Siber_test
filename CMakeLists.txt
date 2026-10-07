cmake_minimum_required(VERSION 3.21)
project(Siber_test VERSION 0.1.0 LANGUAGES CXX)

add_executable(Siber_test main.cpp)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Siber_test)
