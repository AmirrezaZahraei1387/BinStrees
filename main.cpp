#include <iostream>
#include <vector>
#include <functional>
#include "BinSTree/test/test.hpp"


int main() {

    const std::vector<std::function<bool()>> testFuncs;
    for(auto& func: TestBinSTree::testFuncs){
        TestBinSTree::printResult(func());
    }
    return 0;
}