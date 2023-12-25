//
// Created by KAVOSH on 12/25/2023.
//
#include <iostream>
#include <vector>
#include <functional>
#include "test.hpp"


int main() {

    const std::vector<std::function<bool()>> testFuncs;
    for(auto& func: TestBinSTree::testFuncs){
        TestBinSTree::printResult(func());
    }
    return 0;
}
