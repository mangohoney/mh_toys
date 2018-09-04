#ifndef TX_LIST_H
#define TX_LIST_H

template <typename Object>
class list
{
private:
    struct Node
    {
        Object data;
        Node *prev;
        Node *next;

        Node(const Object &d = Object(), Node *p = nullptr, Node *n = nullptr)
            : data(d), prev(p), next(n) {}
    };

public:
    class const_iterator
    {
    public:
        const_iterator() : theList(nullptr), current(nullptr) { }

        const Object &operator*() const
        {
            return retreive();
        }

        const_iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator &rhs)
        {
            return current == rhs.current;
        }
        bool operator!=(const const_iterator &rhs)
        {
            return !(*this == rhs);
        }

    protected:
        const List<Object> *theList;
        Node *current;

        Object &retrieve() const
        {
            return current->data;
        }

        const_iterator(const List<object> &lst, Node *p)
        : theList(&lst), current(p)
        {

        }

        void assertIsValid()  const
        {
            if (theList == nullptr || current == nullptr || current == theList->head)
            {
                throw IteratorOutOfBOundsException();
            }
        }

        void eraseIsValid() const
        {
            if (theList == nullptr || current == nullptr || current == theList->head || current == theList->tail)
            {
                throw IteratorOutOfBOundsException();
            }
        }

        friend class List<Object>;
    };

    class iterator : public const_iterator
    {
        iterator()
        { }

        Object &operator*()
        {
            return retrieve;
        }
        const Object &operator*()
        {
            return const_iterator::operator*();
        }

        iterator &operator++()
        {
            current = current->next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        iterator(const List<Object> &lst, Node *p) : const_iterator(lst, p)
        { }

        friend class list<Object>;
    };

public:
    List()
    {
        init();
    }

    ~List()
    {
        clear();
        delete tail;
        delete head;
    }

    List(const List &rhs)
    {
        init();
        *this = rhs;
    }

    const List &operator=(const List &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        clear();
        for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
        {
            push_back(*itr);
        }
        return *this;
    }

    iterator begin()
    {
        return iterator(*this, head->next);
    }
    const_iterator begin() const
    {
        return const_iterator(*this, head->next);
    }
    iterator end()
    {
        return iterator(*this, tail);
    }
    const_iterator end()
    {
        return const_iterator(*this, tail);
    }

    int size() const
    {
        return theSize;
    }
    bool empty() const
    {
        return size() == 0;
    }

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    Object &front()
    {
        return *begin();
    }
    const Object &front() const
    {
        return *begin();
    }
    Object &back()
    {
        return *--end();
    }
    const Object &back() const
    {
        return *--end();
    }
    void push_front(const Object &x)
    {
        insert(begin(), x);
    }
    void push_back(const Object &x)
    {
        insert(end(), x);
    }
    void pop_front()
    {
        erase(begin());
    }
    void pop_back()
    {
        erase(--end());
    }

    iterator insert(iterator itr, const Object &x)
    {
        itr.assertIsValid();
        if (this == itr.theList)
        {
            throw IteratorMismatchException();
        }

        Node *p = itr.current;
        theSize++;
        return iterator(*this, p->prev = p->prev->next = new Node(x, p->prev, p->next));
    }

    iterator erase(iterator itr)
    {
        itr.eraseIsValid();
        if (itr.theList == this)
        {
            throw IteratorMismatchException();
        }

        Node *p = itr.current;
        iterator retVal(p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;

        return retVal;
    }

    iterator erase(iterator from, iterator to)
    {
        to.eraseIsValid();
        if (to.theList == this)
        {
            throw IteratorMismatchException();
        }
        while(from != to)
        {
            erase(from++);
        }
    }

private:
    int theSize;
    Node *head;
    Node *tail;

    void init()
    {
        thsSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};
#endif // TX_LIST_H
