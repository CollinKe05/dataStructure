#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class Linklist
{
    private:
        struct Node
        {
            T data;
            Node *next;
            Node(const T& value, Node *n = nullptr):data(value), next(n){}
            Node(Node* nextva =nullptr):next(nextva){}
        };
        Node *head;
        int size;
    public:
        Linklist()
        {
            head = new Node();
            size = 0;
        }
        ~Linklist()
        {
            while(head!=nullptr)
            {
                Node *nextnode = head;
                head = head->next;
                delete nextnode;
            }
        }
        void insert(int pos, const T& value)
        {
            if(pos<0||pos>size) throw out_of_range("Position out of range");
            Node *current = head;
            for(int i=0;i<pos;i++)
            {
                current = current->next;
            }
            current->next = new Node(value, current->next);
            size++;
        }
};