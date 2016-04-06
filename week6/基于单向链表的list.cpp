#include <iostream>
#include <string>
using namespace std;

enum Error_code {
   success,
   underflow,
   overflow
};

template <class List_entry>
struct Node {
   List_entry entry;
   Node<List_entry> *next;
};

template <class List_entry>
class MyList
{
   public:
         MyList() : count(0), head(NULL), curPosition(0), current(NULL) {}
         ~MyList() {
            clear();
         }
         // 拷贝构造函数和赋值运算符重载，注意深拷贝与浅拷贝的差异
         MyList(const MyList<List_entry> &copy) {
            curPosition = count = 0;
            head = current = NULL;
            List_entry entry;
            for (int i = 0; i < copy.size(); i++) {
               copy.retrieve(i, entry);   // i 是逐渐递增，可以实现copy
               this->insert(i, entry);
            }
         }
         void operator=(const MyList<List_entry> &copy) {
            this->clear();
            List_entry entry;
            for (int i = 0; i < copy.size(); i++) {
               copy.retrieve(i, entry);
               this->insert(i, entry);
            }
         }
         // 清空list
         void clear() {
            current = head;
            while (head != NULL) {
               head = head->next;
               delete current;
               current = head;
            }
            count = curPosition = 0;
         }
         // 判断list是否为空
         bool empty() const {
            if (count == 0) {
               return true;
            } else {
               return false;
            }
         }
         // 判断list是否已满
         bool full() const {
            Node<List_entry> *temp = new Node<List_entry>;
            if (temp == NULL) {
               return true;
            } else {
               delete temp;
               return false;
            }
         }
         // 获取list的元素数量
         int size() const {
            return count;
         }
         // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，依次类推
         // 若position < 0 或者 position > count，则返回underflow
         Error_code insert(int position, const List_entry &entry) {
            if (position < 0 || position > count) {
               return underflow;
            }
            Node<List_entry> *temp = new Node<List_entry>;
            if (temp == NULL) {
               return overflow;
            }
            temp->entry = entry;
            if (position > 0) {
               setPosition(position - 1);
            }

            if (0 == count) {             // the list is empty now
               temp->next = NULL;
               head = current = temp;
            } else if (0 == position) {      // insert to the head
               temp->next = head;
               head = temp;
            } else {                // normal case
               temp->next = current->next;
               current->next = temp;
            }
            count++;
            return success;
         }
         // 删除第position个位置的元素，并将该元素的值保存在entry中
         // 若position < 0 或者 position >= count，则返回underflow
         Error_code remove(int position, List_entry &entry) {
            if (position < 0 || position >= count) {
               return underflow;
            }
            if (position > 0) {
               setPosition(position - 1);
            } else {
               curPosition = 0;
               current = head;
            }
            if (0 == position) {
               entry = head->entry;
               head = head->next;
               delete current;
               current = head;
            } else {
               Node<List_entry> *temp = current->next;
               entry = current->next->entry;
               current->next = current->next->next;
               delete temp;
            }
            count--;
            return success;
         }
         // 获取第position个位置的元素，保存在entry中
         // 若position < 0 或者 position >= count，则返回underflow
         Error_code retrieve(int position, List_entry &entry) const {
            if (position < 0 || position >= count) {
               return underflow;
            }
            setPosition(position);
            entry = current->entry;
            return success;
         }
         // 将第position个位置的元素替换为entry
         // 若position < 0 或者 position >= count，则返回underflow
         Error_code replace(int position, const List_entry &entry) {
            if (position < 0 || position >= count) {
               return underflow;
            }
            setPosition(position);
            current->entry = entry;
            return success;
         }
         // 用visit函数遍历list内所有的元素
         void traverse(void (*visit)(List_entry &)) {
            curPosition = 0;
            current = head;
            while (curPosition < count) {
               visit(current->entry);
               curPosition++;
               if (curPosition < count) {
                  current = current->next;
               }
            }
            if (curPosition > 0) {
               curPosition--;
            }
         }
   protected:
         int count;                                         // 记录list内元素数量
         Node<List_entry> *head;                            // 链表头指针
         mutable int curPosition;                           // current指针的位置编号
         mutable Node<List_entry> *current;                 // current指针
         // 设置current指针的位置，指向第position个位置
         void setPosition(int position) const {
            if (empty()) return;
            if (position < curPosition) {
               curPosition = 0;
               current = head;
            }
            for (; curPosition != position; curPosition++)
               current = current->next;
         }
};                                 