#ifndef CIRCULAR_LINKED_LIST_H__
#define CIRCULAR_LINKED_LIST_H__
#include "linked_list.h"
#include <iostream>

template <typename T>
struct circular_node : node<T> {
    node<T> *prev;
};

template <typename T>
class circular_linked_list : public linked_list<T> {
    private:
    circular_node<T>* head;
    unsigned long long size;

    public:
    circular_linked_list(){   
        head = nullptr;
        size = 0;
    }
    T last()
    {
        return head->prev->value;
    }
    void remove(T value)
    {
        circular_node<T> *pointer = (circular_node<T>*)(this->find_pointer(value));
        circular_node<T> *prev_pointer = (circular_node<T>*)pointer->prev;
        circular_node<T> *next_pointer = (circular_node<T>*)pointer->next;


        delete pointer;
        size--;
        if(size == 0){
            head = nullptr;
            return;
        }
        
        prev_pointer->next = next_pointer;
        next_pointer->prev = prev_pointer;
    }
    void insert(int index, T value)
    {    
        circular_node<T>* n = new circular_node<T>;
        n->value = value;
        n->next = nullptr;
        n->prev = nullptr;

        if(index == 0){
            if(size != 0) {
                n->next = head;
                n->prev = head->prev;
                n->prev->next = n;
                head->prev = n;
            }
            head = n;
            size++;
            return;
        }

        circular_node<T>* temp = head;
        

        while(index != 1){
            index--;
            temp = (circular_node<T>*)(temp->next);
        }


        n->next = temp->next;
        n->prev = temp;
        temp->next = n;
        ((circular_node<T>*)n->next)->prev = n;
        size++;
    }
    void push(T value)
    {
        circular_node<T>* n = new circular_node<T>;
        n->value = value;
        n->next = head;
        n->prev = head->prev;
        head->prev = n;
        n->prev->next = n;
    }
};

#endif