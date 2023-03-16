cmake_minimum_required(VERSION 3.21)
project(DA2223)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(DA2223
        src/Network.cpp
        src/Network.h
        src/Stations.cpp
        src/Stations.h src/readFiles.cpp src/readFiles.h)
