// Problem#: 16364
// Submission#: 4151715
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using std::cout;
using std::endl;

template <class Record>
struct Node
{
    Record entry;
    Node<Record> *next;
};

template <class Record>
class Sortable_list
{
public:
    Sortable_list() : head(NULL) {}
    ~Sortable_list() {
        Node<Record> *ptr = head;
        while (head->next != NULL) {
            head = head->next;
            delete ptr;
            ptr = head;
        }
        delete head;
        head = NULL;
    }
    // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，以此类推
    // 输入数据中，position满足 0 <= position < 链表元素数量
    void insert(int position, const Record &entry) {
        Node<Record> *temp = new Node<Record>;
        temp->next = NULL;
        temp->entry = entry;
        if (0 == position) {    // insert from the head
            temp->next = head;
            head = temp;
        } else {    // normal insert
            Node<Record> *ptr = head;
            for (int i = 0; i < position - 1; i++) {
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    // 输出链表的内容，每两个元素之间用一个空格隔开，最后一个元素之后没有空格，并且需要换行
    void print() {
        Node<Record> * ptr = head;
        while (ptr->next != NULL) {
            cout << ptr->entry << ' ';
            ptr = ptr->next;
        }
        cout << ptr->entry << endl;
    }
    // 对链表进行归并排序，你可以添加一些辅助函数，但不能改动类的成员变量
    void merge_sort() {
        head = sort(head);
    }
    Node<Record> * getMiddle(Node<Record> * start) {
        int size = 0;
        Node<Record> * cur = start;
        while (cur != NULL) {   // count size
            size++;
            cur = cur->next;
        }
        size = size/2 - 1;
        while (size-- > 0) {    // get the middle position pointer
            start = start->next;
        }
        return start;
    }
    Node<Record> * sort(Node<Record> *first) {
        if (first == NULL || first->next == NULL) {
            return first;
        }
        Node<Record> * mid = getMiddle(first);
        Node<Record> * second = mid->next;
        mid->next = NULL;
        first = sort(first);    // sort the first sequence list
        second = sort(second);    // sort the second sequence list
        return merge_list(first, second);
    }
    Node<Record> * merge_list(Node<Record> *first, Node<Record> * second) {
        if (first == second) return first;
        Node<Record> * ptr = NULL, * cur = NULL;
        if (first == NULL) {
            return second;
        } else if (second == NULL) {
            return first;
        } else if (first->entry > second->entry) {    // determinate the head position after merging
            ptr = cur = second;
            second = second->next;
        } else {
            ptr = cur = first;
            first = first->next;
        }
        while (first != NULL && second != NULL) {
            if (first->entry > second->entry) {
                cur->next = second;
                second = second->next;
            } else {
                cur->next = first;
                first = first->next;
            }
            cur = cur->next;
        }
        while (first != NULL) {
            cur->next = first;
            first = first->next;
            cur = cur->next;
        }
        while (second != NULL) {
            cur->next = second;
            second = second->next;
            cur = cur->next;
        }
        return ptr;
    }
private:
    Node<Record> *head;    // 链表头指针
};                                 