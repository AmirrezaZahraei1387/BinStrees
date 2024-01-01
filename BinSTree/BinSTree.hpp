//
// Created by KAVOSH on 12/18/2023.
//

#ifndef TREES_BINSTREE_HPP
#define TREES_BINSTREE_HPP
#include <memory>




// object need to overload the comparison operators
template<typename object>
class BinSTree{
public:


    BinSTree();
    BinSTree(BinSTree& root_);
    BinSTree(BinSTree&& root_) noexcept;
    ~BinSTree();

    BinSTree& operator =(const BinSTree& binSTree);
    BinSTree& operator =(BinSTree&& binSTree) noexcept;

    bool contain(object&& obj) const{
        return contain(obj, root);
    }

    bool contain(object& obj) const{
        return contain(obj, root);
    }

    object findMin() const{
        return findMin(root)->element;
    }

    object findMax() const{
        return findMax(root)->element;
    }

    void insert(object& obj){
        return insert(obj, root);
    }

    void insert(object&& obj){
        insert(obj, root);
    }


    void remove(object&& obj){
        remove(obj, root);
    }

    void remove(object& obj){
        remove(obj, root);
    }

    bool isEmpty(){
        return root == nullptr;
    }

    void makeEmpty(){
        makeEmpty(root);
    }
    void clone(BinSTree<object> root_) const{
        root = clone(root_.root);
    }

    int getDepth(){
        return getDepth(root);
    }


private:

    struct BinTreeNode{
        object element{};
        BinTreeNode* left{};
        BinTreeNode* right{};
    };

    bool contain(object& obj, BinTreeNode* node) const;
    BinTreeNode* findMin(BinTreeNode* node) const;
    BinTreeNode* findMax(BinTreeNode* node) const;
    // version for copy
    void insert(object& obj, BinTreeNode*& node);
    // version for move
    void insert(object&& obj, BinTreeNode*& node);
    void remove(object& obj, BinTreeNode* &node);
    void makeEmpty(BinTreeNode*& node);
    BinTreeNode* clone(BinTreeNode* root_) const;
    int getDepth(BinTreeNode *& node);

    BinTreeNode* root;
};

#include "BinSTreeMem.inl"
#include "BinSTreeOperations.inl"

#endif //TREES_BINSTREE_HPP
