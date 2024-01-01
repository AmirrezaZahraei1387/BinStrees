//
// Created by KAVOSH on 1/1/2024.
//
#ifndef TREES_AVLPROPERTY_INL
#define TREES_AVLPROPERTY_INL
#include <algorithm>
#include "AVLBinStree.hpp"


template<typename object>
int AVLBinSTree<object>::height(AVLNode *node) {
    return node == nullptr ? -1: node->height;
}

template<typename object>
void AVLBinSTree<object>::balance(AVLNode *&node) {
    if(node == nullptr)
        return;

    if(height(node->left) - height(node->right) > ALLOWED_IMBALANCE){
        if(height(node->left->left) >= height(node->left->right)){
            rotateWithLeft(node);
        }else{
            doubleWithLeft(node);
        }
    }else if(height(node->right) - height(node->left) > ALLOWED_IMBALANCE){
        if(height(node->right->right) >= height(node->right->left)){
            rotateWithRight(node);
        }else{
            doubleWithRight(node);
        }
    }

    node->height = std::max(height(node->left), height(node->right)) + 1;
    std::cout<<node->element<<' '<<node->height<<std::endl;
}

template<typename object>
void AVLBinSTree<object>::rotateWithLeft(AVLNode *&k2) {
    AVLNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template<typename object>
void AVLBinSTree<object>::rotateWithRight(AVLNode *&k2) {
    AVLNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k2->left), k1->height) + 1;
    k2 = k1;
}

template<typename object>
void AVLBinSTree<object>::doubleWithLeft(AVLNode *&k3) {
    rotateWithRight(k3->left);
    rotateWithLeft(k3);
}

template<typename object>
void AVLBinSTree<object>::doubleWithRight(AVLNode *&k3) {
    rotateWithLeft(k3->right);
    rotateWithRight(k3);
}


#endif //TREES_AVLPROPERTY_INL
