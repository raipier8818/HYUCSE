#ifndef STACK_H__
#define STACK_H__

#include "../node/node.h"

template <typename T>
class stack
{
    private:
    list_node<T> *head;
    unsigned long _size;

    public:
    stack(){
        head = nullptr;
        _size = 0;
    }

    void push(T value)
    {
        list_node<T> *n = new list_node<T>();
        n->value = value;
        n->next = head;
        head = n;
        _size++;
    }
    void pop()
    {
        list_node<T> *n = head;
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