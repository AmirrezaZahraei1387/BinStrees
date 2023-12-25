#include <iostream>
#include "BinSTree/BinSTree.hpp"



int main() {
    int i{8};

    BinSTree<int> intTree;
    intTree.insert(6);
    intTree.insert(8);
    intTree.insert(8);
    intTree.insert(1);
    intTree.insert(4);
    intTree.insert(3);


    BinSTree<int> h{BinSTree<int>{intTree}};

    return 0;
}
