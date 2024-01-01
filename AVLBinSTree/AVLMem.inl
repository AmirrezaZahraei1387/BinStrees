//
// Created by KAVOSH on 1/1/2024.
//

#ifndef TREES_AVLMEM_INL
#define TREES_AVLMEM_INL
#include "AVLBinStree.hpp"

template<typename object>
void AVLBinSTree<object>::makeEmpty(AVLNode*& node){
    if (node == nullptr){return;}
    makeEmpty(node->left);
    makeEmpty(node->right);

    delete node;

    node = nullptr;
}

template<typename object>
typename AVLBinSTree<object>::AVLNode* AVLBinSTree<object>::clone(AVLNode *root_) const{
    if(root_ == nullptr)
        return nullptr;
    else
        return new AVLNode{root_->element, clone(root_->left),
                           clone(root_->right),
                           root_->height};

}

template<typename object>
AVLBinSTree<object>::AVLBinSTree():
root() {}

template<typename object>
AVLBinSTree<object>::AVLBinSTree(AVLBinSTree &root_) {
    root = clone(root_.root);
}

template<typename object>
AVLBinSTree<object>::AVLBinSTree(AVLBinSTree &&root_) noexcept {
    root = root_.root;
    root_.root = nullptr;
}

template<typename object>
AVLBinSTree<object>::~AVLBinSTree() {
    makeEmpty(root);
}

template<typename object>
AVLBinSTree<object> &AVLBinSTree<object>::operator=(const AVLBinSTree &binSTree) {
    if(&binSTree == this){
        return *this;
    }

    root = clone(binSTree.root);
    return *this;
}

template<typename object>
AVLBinSTree<object> &AVLBinSTree<object>::operator=(AVLBinSTree &&binSTree) noexcept {
    if(&binSTree == this){
        return *this;
    }

    root = binSTree.root;
    binSTree.root = nullptr;
    return *this;
}

#endif //TREES_AVLMEM_INL
