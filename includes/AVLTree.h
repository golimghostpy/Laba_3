#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include "libs.h"

struct TreeNode {
    string key;
    TreeNode* left;
    TreeNode* right;
    int height;

    string to_string_node();
};

class AVLTree {
private:
    TreeNode* root;

public:
    AVLTree() : root(nullptr) {}

    void insert(string);
    bool search(string) const;
    void remove(string);
    void print() const;
    int getHeight(TreeNode*) const;
    TreeNode* minValueNode(TreeNode*) const;
    int getBalance(TreeNode*);
    TreeNode* insertNode(TreeNode*, string);
    bool searchNode(TreeNode*, string) const;
    TreeNode* removeNode(TreeNode*, string);
    void printNode(TreeNode*, int) const;
    TreeNode* rotateRight(TreeNode*);
    TreeNode* rotateLeft(TreeNode*);
    string to_string_tree() const;
};

#endif // AVLTREE_H_INCLUDED
