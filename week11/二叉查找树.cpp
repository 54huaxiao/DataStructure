// Problem#: 16804
// Submission#: 4262747
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>

#ifndef NODE
#define NODE
template <class Entry>
struct Node
{
    Entry entry;
    Node<Entry> *left;
    Node<Entry> *right;
    Node(const Entry &en)
    {
        entry = en;
        left = NULL;
        right = NULL;
    }
};
#endif

// 二叉查找树的查找函数
// 查找target所在的位置，如果target存在二叉查找树中，则返回该结点的指针
// 否则返回NULL
template <class Entry>
Node<Entry>* BSTree_search(Node<Entry> *root, Entry &target) {
    if (root == NULL) return NULL;
    if (root->entry == target) return root;
    else if (root->entry > target) {
        return BSTree_search(root->left, target);
    }
    else {
        return BSTree_search(root->right, target);
    }
}
// 二叉查找树的插入函数
// 将target插入到二叉查找树中，二叉查找树的结点满足以下条件：
// 1、任意结点的左子树中的元素小于该结点的元素
// 2、任意结点的右子树中的元素大于该结点的元素
// 3、同一个元素在二叉查找树中只会出现一次
template <class Entry>
void BSTree_insert(Node<Entry> *&root, const Entry &target) {
    if (root == NULL) {
        root = new struct Node<Entry>(target);
    }
    else if (root->entry > target) {
        BSTree_insert(root->left, target);
    }
    else {
        BSTree_insert(root->right, target);
    }
}
// 二叉查找树的删除函数
// 如果target存在二叉查找树中，则删除它，否则不进行任何操作
template <class Entry>
void BSTree_remove(Node<Entry> *&root, const Entry &target) {
    if (root == NULL) return;
    if (root->entry == target) {
        if (root->left == NULL) {
            Node<Entry> * old = root;
            if (root->right != NULL) root = root->right;
            else root = NULL;
            delete old;
        }
        else {
            Node<Entry> * old = root->left;
            if (old->right == NULL) {
                root->entry = old->entry;
                if (old->left != NULL) root->left = old->left;
                else root->left = NULL;
                delete old;
            }
            else {
                while (old->right->right != NULL) old = old->right;
                Node<Entry> * cur = old->right;
                root->entry = cur->entry;
                if (cur->left != NULL) old->right = cur->left;
                else old->right = NULL;
                delete cur;
            }
        }
    }
    else if (root->entry > target) {
        BSTree_remove(root->left, target);
    }
    else {
        BSTree_remove(root->right, target);
    }
}                                 