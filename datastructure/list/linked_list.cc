#include <iostream>
#include "linked_list.h"

struct node
{
    int value;
    node *next;
};

node* linked_list::find_pointer(int value)
{
    node *temp = head;
    while (temp != nullptr)
    {   
        if (temp->value == value)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

node* linked_list::find_prev_pointer(int value)
{
    node *temp = head;
    std::cout << value << std::endl;
    while (temp->next != nullptr)
    {
        if (temp->next->value == value)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}


node* linked_list::find_prev_pointer(node* n)
{
    node *temp = head;
    while (temp->next != nullptr)
    {
        if (temp->next == n)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

linked_list::linked_list()
{
    head = nullptr;
    size = 0;
}

bool linked_list::empty()
{
    return size == 0;
}

void linked_list::clear()
{
    node *temp = head;

    while (temp != nullptr)
    {
        node *next = temp->next;
        delete temp;
        temp = next;
    }

    head = nullptr;
    size = 0;
}

int linked_list::first()
{
    return head->value;
}

int linked_list::last()
{
    node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    return temp->value;
}

void linked_list::remove(int value)
{
    node *pointer = find_pointer(value);
    node *prev_pointer = find_prev_pointer(pointer);
    node *next_pointer = pointer->next;


    delete pointer;
    size--;
    if(prev_pointer == nullptr){
        head = nullptr;
        return;
    }
    
    prev_pointer->next = next_pointer;
}

void linked_list::insert(int index, int value)
{    
    node* n = new node;
    n->value = value;
    n->next = nullptr;
    if(size != 0) n->next = head;

    if(index == 0){
        head = n;
        size++;
        return;
    }

    node* temp = head;
    

    while(index != 1){
        index--;
        temp = temp->next;
    }


    n->next = temp->next;
    temp->next = n;
    size++;
}


void linked_list::push(int value)
{
    insert(size, value);
}


int linked_list::find(int value)
{
    node* n_ptr = find_pointer(value);
    return n_ptr->value;
}

void linked_list::print(){
    if(size == 0) return;
    node* temp = head;
    
    while (temp != nullptr)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}