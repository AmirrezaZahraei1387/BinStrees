cmake_minimum_required(VERSION 3.23)
project(Trees)

set(CMAKE_CXX_STANDARD 23)

add_executable(AVLBinSTreeLab
        AVLBinSTree/AVLBinStree.hpp
        AVLBinSTree/AVLProperty.inl
        AVLBinSTree/AVLBinSTreeOperations.inl
        AVLBinSTree/AVLMem.inl
        AVLBinSTree/test/AVLBinSTreeTest.hpp
        AVLBinSTree/test/AVLBinSTreeTest.cpp
        AVLBinSTree/lab/mainLab.cpp)
