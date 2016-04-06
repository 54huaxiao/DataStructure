// Problem#: 16979
// Submission#: 4308725
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#ifndef AVL_NODE
#define AVL_NODE

template <class Entry>
struct AvlNode

{

    Entry entry;

    AvlNode<Entry> *left;

    AvlNode<Entry> *right;

    int bf;                // balance factor 平衡因子
    AvlNode(const Entry &hehe) {
        entry = hehe;
        left = NULL;
        right = NULL;
        bf = 0;
    }
};



#endif
#include<cstdlib>


// 查找AVL树里面是否有元素entry，如果有则返回该结点，没有则返回NULL

template<class Entry>
void rotate_right(AvlNode<Entry>*&root) {
    AvlNode<int>*left = root->left;
    root->left = left->right;
    left->right = root;
    root = left;
}

template<class Entry>
void rotate_left(AvlNode<Entry>*&root) {
    AvlNode<int>*right = root->right;
    root->right = right->left;
    right->left = root;
    root = right;
}

template <class Entry>
AvlNode<Entry> *AVL_search(AvlNode<Entry> *&root, const Entry entry) {
    if (root == NULL)
        return NULL;
    if (root->entry == entry)
        return root;
    if (root->entry > entry)
        return AVL_search(root->left, entry);
    else
        return AVL_search(root->right, entry);
}

template <class Entry>
void balance_left(AvlNode<Entry>*&root) {
    AvlNode<Entry>*&left_root = root->left;
    switch (left_root->bf)
    {
    case -1:
        root->bf = 0;
        left_root->bf = 0;
        rotate_right(root);
        break;
    case 0:
        cout << "centain mistake is happened";
        break;
    case 1:
        AvlNode<Entry>*right_root = left_root->right;
        switch (right_root->bf)
        {
        case -1:
            left_root->bf = 0;
            root->bf = 1;
            right_root->bf = 0;
            break;
        case 0:
            left_root->bf = 0;
            root->bf = 0;
            right_root->bf = 0;
            break;
        case 1:
            left_root->bf = -1;
            right_root->bf = 0;
            root->bf = 0;
            break;
        }
        rotate_left(left_root);
        rotate_right(root);
        break;
    }
}

template<class Entry>
void balance_right(AvlNode<Entry>*&root) {
    AvlNode<Entry>*&right_root = root->right;
    AvlNode<Entry>*sub_tree = right_root->left;
    switch (right_root->bf)
    {
    case -1:
        switch (sub_tree->bf)
        {
        case -1:
            root->bf = 0;
            right_root->bf = 1;
            sub_tree->bf = 0;
            break;
        case 0:
            root->bf = 0;
            right_root->bf = 0;
            sub_tree->bf = 0;
            break;
        case 1:
            root->bf = -1;
            right_root->bf = 0;
            sub_tree->bf = 0;
            break;
        default:
            break;
        }
        rotate_right(right_root);
        rotate_left(root);
        break;
    case 0:
        root->bf = 1;
        break;
    case 1:
        root->bf = 0;
        right_root->bf = 0;
        rotate_left(root);
        break;
    default:
        break;
    }
}

template <class Entry>
void insert(AvlNode<Entry>*&root, const Entry &entry, bool &taller) {
    if (root == NULL) {
        root = new AvlNode < Entry >(entry);
        taller = true;
    }
    else if (entry == root->entry) {
        taller = false;
    }
    else if (entry > root->entry) {
        insert(root->right, entry, taller);
        if (taller == true) {
            switch (root->bf)
            {
            case -1 :
                    root->bf = 0;
                    taller = false;
                    break;
            case 0 :
                    taller = true;
                    root->bf = 1;
                    break;
            case 1 :
                    balance_right(root);
                    taller = false;
                    break;
            }
        }
    }
    else if (entry < root->entry) {
        insert(root->left, entry, taller);
        if (taller == true) {
            switch (root->bf)
            {
            case -1:
                balance_left(root);
                taller = false;
                break;
            case 0:
                taller = true;
                root->bf = -1;
                break;
            case 1:
                taller = false;
                root->bf = 0;
                break;
            }
        }
    }
}


// 将entry插入到AVL树

template <class Entry>

void AVL_insert(AvlNode<Entry> *&root, const Entry entry) {
    bool taller;
    insert(root, entry, taller);
}                                 