//
// Created by KAVOSH on 12/26/2023.
//
#ifndef TREES_RANDOMTREE_INL
#define TREES_RANDOMTREE_INL

#include <random>
#include "../BinSTree.hpp"

template<typename tree_>
void randomIntT(tree_& tree, int nodeN, int min, int max){

    int r{0};

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::uniform_int_distribution<> uid(min, max);

    for(int i{0}; i<nodeN; ++i){
        tree.insert(uid(mt));
    }
}

template<typename tree_>
void randomInsertRemove(tree_& tree, int pN, int min, int max){
    int r{0};

    std::random_device rd;
    std::mt19937 mt{rd()};

    std::uniform_int_distribution<> uid(min, max);

    for(int i{0}; i<pN; ++i){
        r = uid(mt);
        tree.insert(r);

        r = uid(mt);
        tree.remove(r);
    }
}

#endif //TREES_RANDOMTREE_INL
