//
// Created by KAVOSH on 12/18/2023.
//

#ifndef TREES_BINSTREE_HPP
#define TREES_BINSTREE_HPP
#include <memory>


template <typename object>
struct BinTreeNode{
    object element{};
    BinTreeNode* left{};
    BinTreeNode* right{};

};

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

    bool contain(object& obj) const{
        return contain(obj, root);
    }

    bool contain(object&& obj) const{
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
        return insert(obj, root);
    }


    void remove(object& obj){
        return remove(obj, root);
    }

    void remove(object&& obj){
        return remove(obj, root);
    }

    void makeEmpty(){
        return makeEmpty(root);
    }
    BinTreeNode<object>* clone(BinSTree<object> root_) const{
        return clone(root_.root);
    }

private:

    bool contain(object& obj, BinTreeNode<object>* node) const;
    BinTreeNode<object>* findMin(BinTreeNode<object>* node) const;
    BinTreeNode<object>* findMax(BinTreeNode<object>* node) const;
    // version for copy
    void insert(object& obj, BinTreeNode<object>*& node);
    // version for move
    void insert(object&& obj, BinTreeNode<object>*& node);
    void remove(object& obj, BinTreeNode<object>* &node);
    void makeEmpty(BinTreeNode<object>*& node);
    BinTreeNode<object>* clone(BinTreeNode<object>* root_) const;

    BinTreeNode<object>* root;
};

#include "BinSTreeMem.inl"
#include "BinSTreeOperations.inl"

#endif //TREES_BINSTREE_HPP
