enum ErrorCode
{
    success,
    underflow,
    overflow
};


const int maxQueue = 99;


template <class QueueEntry>
class MyQueue
{
public:
    MyQueue() {
        count = 0;
        rear = maxQueue-1;
        front = 0;
    }


    // 判断队列是否为空
    bool empty() const {
        return count == 0;
    }
    // 入队操作
    ErrorCode append(const QueueEntry &item) {
        if (count >= maxQueue) return overflow;
        count++;
        rear = (rear + 1 == maxQueue) ? 0 : (rear + 1);
        entry[rear] = item;
        return success;
    }
    // 出队操作
    ErrorCode serve() {
        if (count <= 0) return underflow;
        count--;
        front = (front + 1 == maxQueue) ? 0 : (front + 1);
        return success;
    }
    // 获取队头元素
    ErrorCode retrieve(QueueEntry &item) const {
        if (count <= 0) return underflow;
        item = entry[front];
        return success;
    }
    // 判断队列是否已满
    bool full() const {
        return count == maxQueue;
    }
    // 获取队列已有元素个数
    int size() const {
        return count;
    }
    // 清除队列所有元素
    void clear() {
        count = 0;
        front = 0;
        rear = maxQueue - 1;
    }
    // 获取队头元素并出队
    ErrorCode retrieve_and_serve(QueueEntry &item) {
        if (count <= 0) return underflow;
        else {
            count--;
            item = entry[front];
            front = (front + 1 == maxQueue) ? 0 : (front + 1);
        }
        return success;
    }


private:
    int front;                             // 队头下标
    int rear;         // 队尾下标
    int count;
    QueueEntry entry[100];       // 队列容器
};                                 
