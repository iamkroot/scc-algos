cmake_minimum_required(VERSION 3.16)
project(scc_algos)
set(CMAKE_CXX_STANDARD 20)

add_executable(scc_algos main.cpp Graph.cpp Graph.h DCSCFinder.tcc KosarajuFinder.tcc UnorderedSet.h)
