#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex; // 永远指向栈顶元素的真实索引（空栈时为 -1）

    // 内部机密：扩容
    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        // 栈的扩容非常无脑，直接按顺序抄过去就行
        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Stack(int initCap = 10) : capacity(initCap), topIndex(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& val) {
        if (topIndex == capacity - 1) {
            resize(); // 满了就自动扩容
        }
        data[++topIndex] = val; // 先让指针上移一格，再放数据
    }

    T pop() {
        if (isEmpty()) throw std::out_of_range("栈已空，无法 pop");
        return data[topIndex--]; // 先把当前数据拿出来，指针再下移一格
    }

    T top() const {
        if (isEmpty()) throw std::out_of_range("栈已空");
        return data[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};