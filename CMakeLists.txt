cmake_minimum_required(VERSION 3.23)
project(Trees)

set(CMAKE_CXX_STANDARD 23)

add_executable(Trees main.cpp BinSTree/BinSTree.hpp BinSTree/BinSTreeOperations.inl BinSTree/BinSTreeMem.inl)
