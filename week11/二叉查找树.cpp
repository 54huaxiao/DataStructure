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

// ����������Ĳ��Һ���
// ����target���ڵ�λ�ã����target���ڶ���������У��򷵻ظý���ָ��
// ���򷵻�NULL
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
// ����������Ĳ��뺯��
// ��target���뵽����������У�����������Ľ����������������
// 1����������������е�Ԫ��С�ڸý���Ԫ��
// 2����������������е�Ԫ�ش��ڸý���Ԫ��
// 3��ͬһ��Ԫ���ڶ����������ֻ�����һ��
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
// �����������ɾ������
// ���target���ڶ���������У���ɾ���������򲻽����κβ���
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