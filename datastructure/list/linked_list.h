#ifndef LINKED_LIST_H__
#define LINKED_LIST_H__

struct node;

class linked_list{
    private:
    node *head;
    int size;
    node* find_pointer(int value);
    node* find_prev_pointer(int value);
    node* find_prev_pointer(node* n);

    public:
    linked_list();
    bool empty();
    void clear();
    int first();
    int last();
    void remove(int value);
    void insert(int index, int value);
    void push(int value);
    int find(int value);
    void print();
};

#endif