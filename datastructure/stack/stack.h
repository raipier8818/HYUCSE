#ifndef STACK_H__
#define STACK_H__

template <typename T>
struct node
{
    T value;
    node<T> *next;
};

template <typename T>
class stack
{
    private:
    node<T> *head;
    unsigned long _size;

    public:
    stack(){
        head = nullptr;
        _size = 0;
    }

    void push(T value)
    {
        node<T> *n = new node<T>();
        n->value = value;
        n->next = head;
        head = n;
        _size++;
    }
    void pop()
    {
        node<T> *n = head;
        head = n->next;
        delete n;
        _size--;
    }
    T top()
    {
        return head->value;
    }
    bool empty()
    {
        return _size == 0;
    }
    unsigned long size()
    {
        return _size;
    }
    void clear(){
        while(_size){
            pop();
        }
    }
};

#endif