CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_DEFINITIONS(-std=c++11)

PROJECT(PlyLoader)

INCLUDE_DIRECTORIES("vcglib")

ADD_LIBRARY(PlyLoader SHARED
            "PlyLoader/PlyLoader.cpp"
            "vcglib/wrap/ply/plylib.cpp")
