//
// Created by KAVOSH on 1/1/2024.
//

#ifndef TREES_AVLBINSTREE_HPP
#define TREES_AVLBINSTREE_HPP

template<typename object>
class AVLBinSTree{
public:


private:
    struct AVLNode{
        int height{};
        AVLNode* left;
        AVLNode* right;
        object element;
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
    int getDepth(AVLNode *& node);
};

#endif //TREES_AVLBINSTREE_HPP
