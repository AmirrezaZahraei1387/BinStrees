//
// Created by KAVOSH on 1/1/2024.
//

#ifndef TREES_AVLBINSTREEOPERATIONS_INL
#define TREES_AVLBINSTREEOPERATIONS_INL
#include <memory>
#include "AVLBinStree.hpp"


template<typename object>
void AVLBinSTree<object>::insert(object& obj, AVLNode*& node){
    if(node == nullptr){
        node = new AVLNode{obj, nullptr, nullptr};
    }else if(obj < node->element){
        insert(obj, node->left);
    }else if(node->element < obj){
        insert(obj, node->right);
    }else{
    }
    balance(node);
}

template<typename object>
void AVLBinSTree<object>::insert(object &&obj, AVLNode *&node) {
    if(node == nullptr){
        node = new AVLNode{std::move(obj), nullptr, nullptr};
    }else if(obj < node->element){
        insert(std::move(obj), node->left);
    }else if(node->element < obj){
        insert(std::move(obj), node->right);
    }else{

    }
    balance(node);
}


template<typename object>
void AVLBinSTree<object>::remove(object &obj, AVLNode *&node) {
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
        AVLNode* oldNode{node};
        node = (node -> left != nullptr)? node->left: node->right;
        delete oldNode;
    }

    balance(node);
}


template<typename object>
bool AVLBinSTree<object>::contain(object& obj, AVLNode* node) const{
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
typename AVLBinSTree<object>::AVLNode* AVLBinSTree<object>::findMin(AVLNode* node) const{
    if(node != nullptr){

        while(node->left != nullptr) {
            node = node->left;
        }
    }
    return node;
}

template<typename object>
typename AVLBinSTree<object>::AVLNode* AVLBinSTree<object>::findMax(AVLNode* node) const{
    if(node != nullptr){

        while(node->right != nullptr) {

            node = node->right;
        }
    }
    return node;
}

#endif //TREES_AVLBINSTREEOPERATIONS_INL
