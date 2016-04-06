#include <iostream>
using namespace std;

enum ErrorCode {
         success,
         underflow,
         overflow
};

template <class QueueEntry>
struct Node
{
         QueueEntry data;
         Node<QueueEntry> *next;
};

template <class QueueEntry>
class MyQueue
{
public:
         MyQueue(): front(NULL), rear(NULL) {}
         // 判断队列是否为空
         bool empty() const {
            if (front == NULL) {
                return true;
            } else {
                return false;
            }
         }
         // 入队操作
         ErrorCode append(const QueueEntry &item) {
            if (front == NULL) {
                rear = front = new Node<QueueEntry>;
                front->data = item;
                front->next = NULL;
                return success;
            } else {
                Node<QueueEntry> *temp = new Node<QueueEntry>;
                temp->data = item;
                temp->next = NULL;
                rear->next = temp;
                rear = temp;
                return success;
            }
         }
         // 出队操作
         ErrorCode serve() {
            Node<QueueEntry> *temp = front;
            if (front == NULL) {
                return underflow;
            } else {
                if (front != rear) {
                    front = front->next;
                } else {    // only one entry
                    front = rear = NULL;
                }
                delete temp;
                return success;
            }
         }
         // 获取队头元素
         ErrorCode retrieve(QueueEntry &item) const {
            if (front == NULL) {
                return underflow;
            } else {
                item = front->data;
                return success;
            }
         }
         // 获取队列已有元素个数
         int size() const {
            Node<QueueEntry> *temp = front;
            int size = 0;
            while (temp != NULL) {
                temp = temp->next;
                size++;
            }
            return size;
         }
         // 清除队列所有元素
         void clear() {
            Node<QueueEntry> *temp = front;
            while (temp != NULL) {
                front = front->next;
                delete temp;
                temp = front;
            }
            front = rear = NULL;
         }
         // 获取队头元素并出队
         ErrorCode retrieve_and_serve(QueueEntry &item) {
            if (front == NULL) {
                return underflow;
            } else {
                Node<QueueEntry> *temp = front;
                item = front->data;
                if (front != rear) {
                    front = front->next;
                } else {    // only one entry
                    front = rear = NULL;
                }
                delete temp;
                return success;
            }
         }
private:
         Node<QueueEntry> *front;                           // 队头指针
         Node<QueueEntry> *rear;                             // 队尾指针

};                                 
