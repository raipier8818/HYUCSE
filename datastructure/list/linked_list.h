#ifndef LINKED_LIST_H__
#define LINKED_LIST_H__
#include <iostream>

template <typename T>
struct node
{
    T value;
    node<T> *next;
};
template <typename T>
class linked_list{
    protected:
    node<T> *head;
    int _size;
    node<T>* find_pointer(T value);
    node<T>* find_prev_pointer(T value);
    node<T>* find_prev_pointer(node<T>* n);

    public:
    linked_list();
    bool empty();
    void clear();
    T first();
    T last();
    void remove(T value);
    void insert(int index, T value);
    void push(T value);
    T find(T value);
    void print();
    int size(){
        return _size;
    }
};



template <typename T>
node<T>* linked_list<T>::find_pointer(T value)
{
    node<T> *temp = head;
    while (temp != nullptr)
    {   
        if (temp->value == value)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
node<T>* linked_list<T>::find_prev_pointer(T value)
{
    node<T> *temp = head;
    std::cout << value << std::endl;
    while (temp->next != nullptr)
    {
        if (temp->next->value == value)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}


template <typename T>
node<T>* linked_list<T>::find_prev_pointer(node<T>* n)
{
    node<T>*temp = head;
    while (temp->next != nullptr)
    {
        if (temp->next == n)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
linked_list<T>::linked_list()
{
    head = nullptr;
    _size = 0;
}

template <typename T>
bool linked_list<T>::empty()
{
    return _size == 0;
}

template <typename T>
void linked_list<T>::clear()
{
    node<T> *temp = head;

    while (temp != nullptr)
    {
        node<T> *next = temp->next;
        delete temp;
        temp = next;
    }

    head = nullptr;
    _size = 0;
}

template <typename T>
T linked_list<T>::first()
{
    return head->value;
}

template <typename T>
T linked_list<T>::last()
{
    node<T> *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    return temp->value;
}

template <typename T>
void linked_list<T>::remove(T value)
{
    node<T> *pointer = find_pointer(value);
    node<T> *prev_pointer = find_prev_pointer(pointer);
    node<T> *next_pointer = pointer->next;


    delete pointer;
    _size--;
    if(prev_pointer == nullptr){
        head = nullptr;
        return;
    }
    
    prev_pointer->next = next_pointer;
}

template <typename T>
void linked_list<T>::insert(int index, T value)
{    
    node<T> *n = new node<T>;
    n->value = value;
    n->next = nullptr;

    if(index == 0){
        if(_size != 0) n->next = head;
        head = n;
        _size++;
        return;
    }

    node<T> *temp = head;
    

    while(index != 1){
        index--;
        temp = temp->next;
    }


    n->next = temp->next;
    temp->next = n;
    _size++;
}


template <typename T>
void linked_list<T>::push(T value)
{
    insert(_size, value);
}


template <typename T>
T linked_list<T>::find(T value)
{
    node<T> *n_ptr = find_pointer(value);
    return n_ptr->value;
}

template <typename T>
void linked_list<T>::print(){
    if(_size == 0) return;
    node<T> *temp = head;
    
    while (temp != nullptr)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

#endif