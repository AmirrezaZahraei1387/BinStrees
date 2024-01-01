#include <iostream>
#include "../BinSTree.hpp"
#include "randomTree.hpp"



int main() {
    BinSTree<int> tree;

    randomIntT<BinSTree<int>>(tree, 1'000'000, 0, 1'000);
    std::cout<<"depth before random insertion deletion pairs: "<<tree.getDepth()<<std::endl;
    randomInsertRemove<BinSTree<int>>(tree, 1'000'000, 0, 1'000'000);
    std::cout<<"depth after random insertion deletion pairs: "<<tree.getDepth()<<std::endl;
    return 0;
}
