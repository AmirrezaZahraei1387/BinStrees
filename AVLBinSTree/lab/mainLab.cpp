//
// Created by KAVOSH on 1/1/2024.
//
#include <cmath>
#include <iostream>
#include "../../BinSTree/lab/randomTree.hpp"
#include "../AVLBinStree.hpp"


int main(){
    AVLBinSTree<int> tree;
    int constexpr NODE_NUM{1000};

    randomIntT(tree, NODE_NUM, 0, 100000);

    std::cout<<"Actual Height"<<tree.getHeight()<<std::endl;
    std::cout<<"Expected Height"<<std::log2(NODE_NUM)<<std::endl;
}

