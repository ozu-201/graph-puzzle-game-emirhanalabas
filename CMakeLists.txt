cmake_minimum_required(VERSION 3.25)
project(graph_puzzle_game_emirhanalabas)

set(CMAKE_CXX_STANDARD 14)

include_directories(Array)
include_directories(Array/Graph)
include_directories(Array/Heap)
include_directories(List/Graph)

add_executable(graph_puzzle_game_emirhanalabas
        Array/Graph/Graph.cpp
        Array/Graph/Graph.h
        Array/Heap/Heap.cpp
        Array/Heap/Heap.h
        Array/Heap/HeapNode.cpp
        Array/Heap/HeapNode.h
        Array/Heap/MinHeap.cpp
        Array/Heap/MinHeap.h
        Array/DisjointSet.cpp
        Array/DisjointSet.h
        Array/Set.cpp
        Array/Set.h
        List/Graph/Edge.cpp
        List/Graph/Edge.h
        List/Graph/EdgeList.cpp
        List/Graph/EdgeList.h
        List/Graph/Graph.cpp
        List/Graph/Graph.h General/AbstractGraph.cpp General/Path.cpp List/Node.cpp List/Queue.cpp Array/Element.cpp Array/Queue.cpp main.cpp)
