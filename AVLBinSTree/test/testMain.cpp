//
// Created by KAVOSH on 1/1/2024.
//
#include <iostream>
#include <vector>
#include <functional>
#include "AVLBinSTreeTest.hpp"


int main() {

    const std::vector<std::function<bool()>> testFuncs;
    for(auto& func: AVLBinSTreeTest::testFuncs){
        AVLBinSTreeTest::printResult(func());
    }
    return 0;
}