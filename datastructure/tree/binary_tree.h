#ifndef BINARY_TREE_H__
#define BINARY_TREE_H__

#include <iostream>
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../node/node.h"

template <typename T>
class binary_tree
{
private:
    unsigned long _size;
    unsigned long _height;

    tree_node<T> *head;

    tree_node<T> *find_pos(T value)
    {
        tree_node<T> *temp = head;

        queue<tree_node<T> *> q;
        q.push(temp);
        while (!q.empty())
        {
            tree_node<T> *cur = q.front();
            q.pop();
            if (cur->value == value)
                return cur;

            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }

            if (cur->right == nullptr)
            {
                q.push(cur->right);
            }
        }
        return nullptr;
    }

public:
    binary_tree()
    {
        _size = 0;
        _height = 0;
        head = nullptr;
    }

    binary_tree(binary_tree<T> &temp)
    {
        _size = temp.size();
        _height = temp.height();
        head = temp.head;
    }

    void insert(T value)
    {
        tree_node<T> *n;
        n->value = value;
        n->left = nullptr;
        n->right = nullptr;
        n->parent = nullptr;

        if (head == nullptr)
        {
            head = n;
            return;
        }

        tree_node<T> *temp = head;

        queue<tree_node<T> *> q;
        q.push(temp);
        while (!q.empty())
        {
            tree_node<T> *cur = q.front();
            q.pop();

            if (cur->left == nullptr)
            {
                n->parent = cur;
                cur->left = n;
                return;
            }
            else
            {
                q.push(cur->left);
            }

            if (cur->right == nullptr)
            {
                n->parent = cur;
                cur->right = n;
                return;
            }
            else
            {
                q.push(cur->right);
            }
        }
    }

    T find(T value)
    {
        tree_node<T> *n = find_pos(value);
        return n->value;
    }

    unsigned long level(T value)
    {
        tree_node<T> *n = find_pos(value);
        if (n == nullptr)
            return 0;
        int l = 0;
        while (n != nullptr)
        {
            l++;
        }
        return l;
    }

    unsigned long size()
    {
        return _size;
    }

    unsigned long height(tree_node<T> *temp = nullptr)
    {
        if (temp == nullptr)
            temp = head;

        int h = 0;

        if (temp->left != nullptr)
        {
            int h_left = height(temp->left);
            h = h_left > h ? h_left : h;
        }

        if (temp->right != nullptr)
        {
            int h_right = height(temp->right);
            h = h_right > h ? h_right : h;
        }

        return h + 1;
    }

    void inorder(tree_node<T> *temp = nullptr)
    {
        if (temp == nullptr)
            temp = head;

        if (temp->left != nullptr){
            inorder(temp->left);
        }
        std::cout << temp->value << " ";
        if(temp->right != nullptr){
            inorder(temp->right);
        }

    }
    void preorder(tree_node<T> *temp = nullptr)
    {
        if (temp == nullptr)
            temp = head;

        std::cout << temp->value << " ";
        if (temp->left != nullptr)
        {
            preorder(temp->left);
        }
        if (temp->right != nullptr)
        {
            preorder(temp->right);
        }

    }
    void postorder(tree_node<T> *temp = nullptr)
    {
        if (temp == nullptr)
            temp = head;

        if (temp->left != nullptr)
        {
            postorder(temp->left);
        }
        if (temp->right != nullptr)
        {
            postorder(temp->right);
        }

        std::cout << temp->value << " ";
    }
};

#endif