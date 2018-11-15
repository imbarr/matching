cmake_minimum_required(VERSION 3.10)
project(matching)

set(CMAKE_CXX_STANDARD 11)

add_executable(matching main.cpp util.cpp util.h algorithm.cpp algorithm.h graph/graph.cpp
        graph/graph.h graph/edge.cpp graph/edge.h graph/bipartiteGraph.cpp
        graph/bipartiteGraph.h graph/flowNetwork.cpp graph/flowNetwork.h augmentingPath.cpp augmentingPath.h)