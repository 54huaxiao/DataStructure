// Problem#: 16980
// Submission#: 4300968
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

#ifndef AVL_NODE
#define AVL_NODE

template<class Entry>
struct AvlNode 
{
    Entry entry;
    AvlNode<Entry> *left;
    AvlNode<Entry> *right;
    int bf;
};

#endif

int abs(int num) {
    return num > 0 ? num : -num;
}

template<class Entry>
int get_Tree_height(AvlNode<Entry> *&root) {
    if (root == NULL) return 0;
    int height = 1;
    int left_h = get_Tree_height(root->left);
    int right_h = get_Tree_height(root->right);
    height += (left_h > right_h ? left_h : right_h);
    return height;
}

template<class Entry>
bool is_AVL_Tree(AvlNode<Entry> *&root) {
    if (root == NULL) return true;
    bool ans = true;
    int left_height, right_height;
    left_height = get_Tree_height(root->left);
    right_height = get_Tree_height(root->right);
    if (abs(left_height - right_height) > 1) return false;
    ans = is_AVL_Tree(root->left);
    if (ans) {
        ans = is_AVL_Tree(root->right);
    }
    return ans;
}                                 