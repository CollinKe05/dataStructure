#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>

class DoubleLinklist
{
    private:
        struct Node
        {
            T data;
            Node *prev;
            Node *next;
            Node(Node* nextva =nullptr):next(nextva),prev(nullptr){}
        };
        Node *head;
        int size;
    public:
        DoubleLinklist():head(nullptr), size(0){}
        ~DoubleLinklist()
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
            Node *newnode = new Node(value, current);
            if(current!=nullptr)
            {
                newnode->prev = current->prev;
                if(current->prev!=nullptr)
                {
                    current->prev->next = newnode;
                }
                current->prev = newnode;
            }
            else
            {
                newnode->prev = nullptr;
                head = newnode;
            }
            size++;
        }
};