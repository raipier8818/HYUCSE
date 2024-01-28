#ifndef NODE_H_
#define NODE_H_

template <typename T>
struct list_node
{
    T value;
    list_node<T> *next;
};

template <typename T>
struct tree_node
{
    T value;
    tree_node<T> *parent;
    tree_node<T> *left;
    tree_node<T> *right;
};

#endif
