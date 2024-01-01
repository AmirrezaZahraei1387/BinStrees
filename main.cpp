#include <iostream>
#include "AVLBinSTree/AVLBinStree.hpp"


int main() {

    int i{8};
    std::cout<<'h'<<std::endl;
    AVLBinSTree<int> tree;
    tree.insert(i);
    std::cout<<tree.contain(i);
    return 0;
}
