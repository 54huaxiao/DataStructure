#include<iostream>
using namespace std;
enum ErrorCode
{
         success,
         underflow,
         overflow
};

template <class StackEntry>
struct Node
{
         StackEntry data;
         Node *next;
};

template <class StackEntry>
class MyStack
{
public:
         MyStack() {
         pTop = NULL;
         }
         /*
                   判断栈是否为空，若为空则返回true，非空则返回false
          */
         bool empty() const {
            if (pTop == NULL) {
                return true;
            } else {
                return false;
            }
         }
         int size() const {
            Node<StackEntry> *temp = pTop;
            int size = 0;
            while (temp != NULL) {
                temp = temp->next;
                size++;
            }
            return size;
         }
         /*
                   出栈操作，若正常出栈则返回success，若栈内无元素则返回underflow
          */
         ErrorCode pop() {
            Node<StackEntry> *temp = pTop;
            if (temp != NULL) {
                pTop = pTop->next;
                delete temp;
                return success;
            } else {
                return underflow;
            }
         }
         /*
                获取栈顶元素，若正常出栈则返回success，若栈内无元素则返回underflow
                   元素内容保存在引用参数item中
          */
         ErrorCode top(StackEntry &item) const {
            if (pTop == NULL) {
                return underflow;
            } else {
                item = pTop->data;
                return success;
            }
         }
         /*
                   入栈操作，若正常入栈则返回success，若入栈失败则返回overflow
          */
         ErrorCode push(const StackEntry &item) {
            if (pTop == NULL) {
                pTop = new Node<StackEntry>;
                pTop->data = item;
                pTop->next = NULL;
                return success;
            } else {
                Node<StackEntry> *temp = new Node<StackEntry>;
                temp->data = item;
                temp->next = pTop;
                pTop = temp;
                return success;
            }
            return overflow;
         }
         /*
                   清空栈
          */
         void clear() {
            Node<StackEntry> *temp = pTop;
            while (pTop != NULL) {
                pTop = pTop->next;
                delete temp;
                temp = pTop;
            }
         }
private:
         Node<StackEntry> *pTop;
};                                 
