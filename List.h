#pragma once
#include "Node.h"
#include <iostream>

template<typename T>
class List
{
    Node<T>* top_;
    List(const List&) = delete;             // disable copy ctor
    List& operator=(const List&) = delete;  // disable assignment operator
public:
    List();
    ~List();
    void push(T object);
    T pop();
    const Node<T>* top() const;
    bool remove(T object);
    const Node<T>* find(T object) const;
    unsigned length();
    void clear() {
        Node<T>* ptr = top_;
        while (ptr)
        {
            top_ = top_->next();
            delete ptr;
            ptr = top_;
        }
    }

  //  friend std::ostream& operator<<(std::ostream& out, const List<T>& L);
};



template<typename T> std::ostream& operator<<(std::ostream& out, const List<T>& L)
{
    const Node<T>* ptr = L.top(); 
    while (ptr)
    {
        out << (*ptr) << '\t';
        ptr = ptr->next();
    }
    return out;
}

template<typename T> List<T>::List()
    : top_(0)
{}

template<typename T> List<T>::~List()
{
    //Node<T>* ptr = top_;
    //while (ptr)
    //{
    //    top_ = top_->next();
    //    delete ptr;
    //    ptr = top_;
    //}
    clear();
}

template<typename T> void List<T>::push(T object)
{
    Node<T>* ptr = new Node<T>(object, top_);
    top_ = ptr;
}

template<typename T> const Node<T>* List<T>::top() const
{
    return top_;
}

template<typename T> T List<T>::pop()
{
    Node<T>* ptr = top_;
    top_ = top_->next();
    T data = ptr->data();
    delete ptr;
    return data;
}

template<typename T> const Node<T>* List<T>::find(T object) const
{
    const Node<T>* ptr = top();
    while (ptr)
    {
        if (ptr->data() == object)
        {
            return ptr;
        }
        ptr = ptr->next();
    }
    return 0;
}

template<typename T>
inline unsigned List<T>::length()
{
    const Node<T>* ptr = top();
    unsigned count = 0;
    while (ptr)
    {
        ++count;
        ptr = ptr->next();
    }
    return count;
}

template<typename T> bool List<T>::remove(T object)
{
    if (!find(object))
    {
        std::cout << object << " not found\n";
        return false;
    }
    Node<T>* ptr2current = top_;
    Node<T>* ptr2previous = top_;
    if (top_->data() == object)
    {
        top_ = top_->next();
        delete ptr2current;
        return true;
    }
    while (ptr2current)
    {
        ptr2current = ptr2current->next();
        if (ptr2current->data() == object)
        {
            ptr2previous->next() = ptr2current->next();
            delete ptr2current;
            return true;
        }
        ptr2previous = ptr2current;
    }
    return false;
}