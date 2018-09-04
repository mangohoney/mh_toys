#ifndef TX_STACK_LIST_H
#define TX_STACK_LIST_H

template <typename Object>
class Stack
{
private:
    struct Node
    {
        Object data;
        Node *next;
        Node(const Object &d = Object(), Node *p = nullptr)
        : data(d), next(p)
        {

        }
    };
public:
    ~Stack()
    {
        while(back != nullptr)
        {
            pop_back();
        }
    }
    Object &top()
    {
        check();
        return back->data;
    }
    Object pop()
    {
        check();
        Node *old = back;
        Object olddata = back->data;
        back = back->next;
        delete old;
        return olddata;
    }
    void push_back(const Object &data)
    {
        back = back != nullptr ? new Node(data, back->next) : new Node(data);
    }
    void check() const
    {
        if (back == nullptr)
        {
            throw EmptyStack();
        }
    }
private:
    Node *back = nullptr;
};
#endif // TX_STACK_LIST_H
