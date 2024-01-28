#ifndef LINKED_LIST_H__
#define LINKED_LIST_H__
#include <iostream>

template <typename T>
struct list_node
{
    T value;
    list_node<T> *next;
};
template <typename T>
class linked_list{
    protected:
    list_node<T> *head;
    int _size;
    list_node<T>* find_pointer(T value);
    list_node<T>* find_prev_pointer(T value);
    list_node<T>* find_prev_pointer(list_node<T>* n);

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
list_node<T>* linked_list<T>::find_pointer(T value)
{
    list_node<T> *temp = head;
    while (temp != nullptr)
    {   
        if (temp->value == value)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
list_node<T>* linked_list<T>::find_prev_pointer(T value)
{
    list_node<T> *temp = head;
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
list_node<T>* linked_list<T>::find_prev_pointer(list_node<T>* n)
{
    list_node<T>*temp = head;
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
    list_node<T> *temp = head;

    while (temp != nullptr)
    {
        list_node<T> *next = temp->next;
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
    list_node<T> *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    return temp->value;
}

template <typename T>
void linked_list<T>::remove(T value)
{
    list_node<T> *pointer = find_pointer(value);
    list_node<T> *prev_pointer = find_prev_pointer(pointer);
    list_node<T> *next_pointer = pointer->next;

    // using namespace std;
    // cout << pointer << endl;
    // cout << prev_pointer << endl;
    // cout << next_pointer << endl;
    
    if(prev_pointer == nullptr){
        head = next_pointer;
    }else {
        prev_pointer->next = next_pointer;
    }

    _size--;
    delete pointer;
}

template <typename T>
void linked_list<T>::insert(int index, T value)
{    
    list_node<T> *n = new list_node<T>;
    n->value = value;
    n->next = nullptr;

    if(index == 0){
        if(_size != 0) n->next = head;
        head = n;
        _size++;
        return;
    }

    list_node<T> *temp = head;
    

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
    list_node<T> *n_ptr = find_pointer(value);
    return n_ptr->value;
}

template <typename T>
void linked_list<T>::print(){
    if(_size == 0) return;
    list_node<T> *temp = head;
    
    while (temp != nullptr)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

#endif