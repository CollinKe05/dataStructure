#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Linklist
{ 
    private:
        struct Node
        {
            T data;
            Node *next;
            Node(T value):data(value),next(NULL){}
        };
        Node *head;
        int size;

    public:
        Linklist()
        {
            head = NULL;
            size = 0;
        }
        ~Linklist()
        {
            Node *current = head;
            while(current!=NULL)
            {
                Node *nextnode = current->next;
                delete current;
                current = nextnode;
            }
        }
        T get(int pos)
        {
            if(pos<0||pos>=size) throw out_of_range("Position out of range");
            Node *current = head;
            for(int i=0;i<pos;i++)
            {
                current = current->next;
            }
            return current->data;
        }
        void insert(int pos, T value)
        {
            if(pos<0||pos>size) throw out_of_range("Position out of range");
            Node *newnode = new Node(value);
            if(pos==0)
            {
                newnode->next = head;
                head = newnode;
            }
            else
            {
                Node *current = head;
                for(int i=0;i<pos-1;i++)
                {
                    current = current->next;
                }
                newnode->next = current->next;
                current->next = newnode;
            }
            size++;
        }
        void remove(int pos)
        {
            if(pos<0||pos>=size) throw out_of_range("Position out of range");
            Node *todelete;
            if(pos==0)
            {
                todelete = head;
                head = head->next;
            }
            else
            {
                Node *current = head;
                for(int i=0;i<pos-1;i++)
                {
                    current = current->next;
                }
                todelete = current->next;
                current->next = todelete->next;
            }
            delete todelete;
            size--;
        }
        
};
