#ifndef QUEUE_H__
#define QUEUE_H__

template <typename T>
struct node
{
    T value;
    node<T> *next;
};

template <typename T>
class queue
{
private:
    node<T> *head;
    node<T> *tail;
    unsigned long _size;

public:
    queue()
    {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

    void push(T value)
    {
        node<T> *n = new node<T>();
        n->value = value;
        n->next = nullptr;
        if(_size == 0){
            head = n;
            tail = n;
            _size++;
            return;
        }

        tail->next = n;
        tail = n;

        _size++;
    }
    void pop()
    {
        node<T> *n = head;
        head = n->next;
        delete n;
        _size--;
    }
    T front()
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
    void clear()
    {
        while (_size)
        {
            pop();
        }
    }
};

#endif 