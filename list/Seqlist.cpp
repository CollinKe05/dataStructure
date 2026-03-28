#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>

class Seqlist
{
    private:
        T* data;
        int size;
        int capacity;

        void expand()
        {
            capacity *= 2;
            T* newdata=new T[capacity];
            for(int i=0;i<size;i++)
            {
                newdata[i]=data[i];
            }
            delete[] data;
            data=newdata;
        }
    public:
        Seqlist(int cap=10):capacity(cap),size(0)
        {
            data=new T[capacity];
        }
        ~Seqlist()
        {
            delete[] data;
        }
        void insert(int pos, T value)
        {
            if(pos<0||pos>size) throw out_of_range("Position out of range");
            if(size>=capacity) expand();
            for(int i=size;i>pos;i--)
            {
                data[i]=data[i-1];
            }
            data[pos]=value;
            size++;
        }
        void remove(int pos)
        {
            if(pos<0||pos>=size) throw out_of_range("Position out of range");
            for(int i=pos;i<size-1;i++)
            {
                data[i]=data[i+1];
            }
            size--;
        }
        T get(int pos)
        {
            if(pos<0||pos>=size) throw out_of_range("Position out of range");
            return data[pos];
        }
};
