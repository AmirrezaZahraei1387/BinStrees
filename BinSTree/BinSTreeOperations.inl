//
// Created by KAVOSH on 12/21/2023.
//
#ifndef TREES_BINSTREEOPERATIONS_INL
#define TREES_BINSTREEOPERATIONS_INL
#include "BinSTree.hpp"

template<typename object>
void BinSTree<object>::insert(object &obj, BinTreeNode<object> *& node) {
    if(node == nullptr){
        node = new BinTreeNode<object>{obj, nullptr, nullptr};
    }else if(obj < node->element){
        insert(obj, node->left);
    }else if(node->element < obj){
        insert(obj, node->right);
    }else {

    }
}

template<typename object>
void BinSTree<object>::insert(object &&obj, BinTreeNode<object> *& node) {

    if(node == nullptr){
        node = new BinTreeNode<object>{std::move(obj), nullptr, nullptr};
    }else if(obj < node->element){
        insert(std::move(obj), node->left);
    }else if(node->element < obj){
        insert(std::move(obj), node->right);
    }else {

    }
}

template<typename object>
void BinSTree<object>::remove(object &obj, BinTreeNode<object> *&node) {
    if(node == nullptr) // we can not remove the nullptr
        return;

    if(obj < node->element)
        remove(obj, node->left);

    else if(obj > node->element)
        remove(obj, node->right);

    else if(node->right != nullptr && node->left != nullptr){
        node->element = findMin(node->right)->element;
        remove(node->element, node->right);
    }else{
        BinTreeNode<object>* oldNode{node};
        node = (node -> left != nullptr)? node->left: node->right;
        delete oldNode;
    }
}

template<typename object>
bool BinSTree<object>::contain(object& obj, BinTreeNode<object> *node) const{
    auto& currentNode{node};
    while(true){
        if (currentNode == nullptr) {
            return false;
        }
        if (obj < node->element) {
            currentNode = currentNode->left;

        } else if (obj > node->element) {
            currentNode = currentNode->right;

        } else {
            return true;
        }
    }
}

template<typename object>
BinTreeNode<object> *BinSTree<object>::findMin(BinTreeNode<object>* node) const {
    if(node != nullptr){

        while(node->left != nullptr) {
            node = node->left;
        }
    }
    return node;
}

template<typename object>
BinTreeNode<object> *BinSTree<object>::findMax(BinTreeNode<object> *node) const{
    if(node != nullptr){

        while(node->right != nullptr) {

            node = node->right;
        }
    }
    return node;
}

template<typename object>
int BinSTree<object>::getDepth(BinTreeNode<object> *& node) {
    if(node == nullptr){
        return 0;
    }

    int leftDepth  = getDepth(node->left);
    int rightDepth = getDepth(node->right);

    if(leftDepth > rightDepth){
        return leftDepth + 1;
    }
    return rightDepth + 1;
}

#endif //TREES_BINSTREEOPERATIONS_INL
