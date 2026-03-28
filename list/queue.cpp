template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int front; // 指向队头元素
    int rear;  // 指向队尾元素的后一个空位（Weiss 喜欢这种定义）
    int size;  // 记录实际元素个数，有了它判断空/满极其简单

    // 核心硬骨头：循环队列的“解包”扩容
    void resize() {
        int newCapacity = capacity * 2;
        T* newData = new T[newCapacity];
        
        // 必须按“逻辑顺序”一个个搬运，不能按“物理顺序”！
        for (int i = 0; i < size; ++i) {
            // (front + i) % capacity 能够算出从队头开始的正确物理索引
            newData[i] = data[(front + i) % capacity];
        }
        
        delete[] data;
        data = newData;
        // 搬入新家后，所有人从 0 重新站队
        front = 0;
        rear = size; 
        capacity = newCapacity;
    }

public:
    Queue(int initCap = 10) : capacity(initCap), front(0), rear(0), size(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& val) {
        if (size == capacity) {
            resize(); 
        }
        data[rear] = val;
        // 尾指针向后走一步，如果到底了就绕回 0
        rear = (rear + 1) % capacity; 
        size++;
    }

    T dequeue() {
        if (isEmpty()) throw std::out_of_range("队列已空，无法 dequeue");
        
        T retVal = data[front];
        // 头指针向后走一步，如果到底了就绕回 0
        front = (front + 1) % capacity;
        size--;
        return retVal;
    }

    bool isEmpty() const {
        return size == 0;
    }
};