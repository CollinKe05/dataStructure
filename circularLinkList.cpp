#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class CircularLinkedList {
private:
    struct CNode {
        int data;
        CNode* next;
        CNode(int val) : data(val), next(nullptr) {}
    };

    CNode* head;
    int size;

public:
    CircularLinkedList() : head(nullptr), size(0) {}

    // 尾部插入：看看尾巴是怎么重新咬住头的
    void push_back(int value) {
        CNode* newNode = new CNode(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // 只有一栋房子时，自己咬自己
        } else {
            // 1. 顺着头找到目前的最后一栋房子
            CNode* tail = head;
            while (tail->next != head) { // 注意这里的结束条件变了！
                tail = tail->next;
            }
            
            // 2. 断开重连
            tail->next = newNode;   // 老尾巴的 next 指向新房子
            newNode->next = head;   // 新房子（新尾巴）的 next 重新指向头节点
        }
        size++;
    }
    
    // 遍历打印：展示如何防止死循环
    void print() {
        if (head == nullptr) return;
        
        CNode* curr = head;
        do {
            std::cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head); // 只要还没绕回起点，就继续走
        std::cout << std::endl;
    }
};