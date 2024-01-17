#include <iostream>


struct node{
    int value;
    node* next;
};

class linked_list{
    private:
    node *head;
    int size;

    node* find_pointer(int value){
        node* temp = head;
        while (temp != nullptr){
            if(temp->value == value) return temp;
            temp = temp->next;
        }
        return nullptr;        
    }

    node* find_prev_pointer(int value){
        node* temp = head;
        while (temp->next != nullptr){
            if(temp->next->value == value) return temp;
            temp = temp->next;
        }
        return nullptr;       
    }

    public:
    linked_list(){
        head = nullptr;
        size = 0;
    }

    bool empty(){
        return size == 0;
    }

    void clear(){
        node* temp = head;

        while(temp != nullptr){
            node* next = temp->next;
            delete temp;
            temp = next;
        }

        head = nullptr;
        size = 0;
    }

    int first(){
        return head->value;
    }

    int last(){
        node* temp = head;

        while(temp->next != nullptr){
            temp = temp->next;
        }

        return temp->value;
    }

    void remove(int value){
        node* prev_pointer = find_prev_pointer(value);
        node* pointer = find_pointer(value);
        node* next_pointer = pointer->next;
        
        delete pointer;
        if(next_pointer == nullptr) return;
        
        prev_pointer->next = next_pointer;
    }

    void insert(int index, int value){
        if(index >= size) return;

        node* temp = head;
        while(temp->next != nullptr){
            index--;
            temp = temp->next;
        }

        node n;
        n.value = value;
        n.next = temp->next;
        temp->next = &n;
    }

    int find(int value){
        return find_pointer(value)->value;
    }
};
