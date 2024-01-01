//
// Created by KAVOSH on 12/21/2023.
//

#ifndef TREES_BINSTREEMEM_INL
#define TREES_BINSTREEMEM_INL
#include "BinSTree.hpp"

template<typename object>
BinSTree<object>::BinSTree():
        root()
{}


template<typename object>
BinSTree<object>::BinSTree(BinSTree &root_)
{
    root = clone(root_.root);
}

template<typename object>
BinSTree<object>::BinSTree(BinSTree &&root_) noexcept{
    root = root_.root;
    root_.root = nullptr;

}

template<typename object>
BinSTree<object>::~BinSTree() {
    makeEmpty(root);
}

template<typename object>
BinSTree<object>& BinSTree<object>::operator=(const BinSTree<object> &binSTree) {
    if(&binSTree == this){
        return *this;
    }

    root = clone(binSTree.root);
    return *this;
}

template<typename object>
BinSTree<object>& BinSTree<object>::operator=(BinSTree<object> &&binSTree) noexcept{
    if(&binSTree == this){
        return *this;
    }

    root = binSTree.root;
    binSTree.root = nullptr;
    return *this;
}

template<typename object>
void BinSTree<object>::makeEmpty(BinTreeNode*& node) {
    if (node == nullptr){return;}
    makeEmpty(node->left);
    makeEmpty(node->right);

    delete node;

    node = nullptr;
}

template<typename object>
typename BinSTree<object>::BinTreeNode* BinSTree<object>::clone(BinTreeNode *root_) const{
    if(root_ == nullptr)
        return nullptr;
    else
        return new BinTreeNode{root_->element, clone(root_->left), clone(root_->right)};

}
#endif //TREES_BINSTREEMEM_INL
