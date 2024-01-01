//
// Created by KAVOSH on 1/1/2024.
//

#ifndef TREES_AVLBINSTREE_HPP
#define TREES_AVLBINSTREE_HPP

template<typename object>
class AVLBinSTree{
public:

    AVLBinSTree();
    AVLBinSTree(AVLBinSTree& root_);
    AVLBinSTree(AVLBinSTree&& root_) noexcept;
    ~AVLBinSTree();

    AVLBinSTree& operator =(const AVLBinSTree& binSTree);
    AVLBinSTree& operator =(AVLBinSTree&& binSTree) noexcept;

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
    void clone(AVLBinSTree<object> root_) const{
        root = clone(root_.root);
    }

    int getHeight(){
        return height(root);
    }


private:
    struct AVLNode{
        object element;
        AVLNode* left;
        AVLNode* right;
        int height{};
    };

    static constexpr int ALLOWED_IMBALANCE = 1;

    int height(AVLNode *node);
    void balance(AVLNode *&node);

    void rotateWithLeft(AVLNode *& k2);
    void rotateWithRight(AVLNode*& k2);

    void doubleWithLeft(AVLNode *& k3);
    void doubleWithRight(AVLNode *& k3);

    void insert(object& obj, AVLNode*& node);
    void insert(object&& obj, AVLNode*& node);
    void remove(object &obj, AVLNode *&node);
    AVLNode* clone(AVLNode *root_) const;

    bool contain(object& obj, AVLNode* node) const;
    AVLNode* findMin(AVLNode* node) const;
    AVLNode* findMax(AVLNode* node) const;
    void makeEmpty(AVLNode*& node);

    void printTree(){
    }

    AVLNode* root;


};


#include "AVLProperty.inl"
#include "AVLMem.inl"
#include "AVLBinSTreeOperations.inl"
#endif //TREES_AVLBINSTREE_HPP
