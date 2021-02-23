#pragma once
#include <iostream>

template<typename T>
class Node
{
    T  data_;
    Node* next_;
    Node(const Node&) = delete;             // disable copy ctor
    Node& operator=(const Node&) = delete;  // disable assignment operator
public:
    Node();
    Node(T d, Node* n);
    const T& data() const;
    T& data();
    Node* next() const;
    Node*& next();
   // friend std::ostream& operator<<(std::ostream& out, const Node<T>& N);
};

template<typename T> Node<T>::Node()
    : data_(), next_(0)
{}

template<typename T> Node<T>::Node(T d, Node* n)
    : data_(d), next_(n)
{}

template<typename T> const T& Node<T>::data() const
{
    return data_;
}

template<typename T> T& Node<T>::data()
{
    return data_;
}

template<typename T> Node<T>* Node<T>::next() const
{
    return next_;
}

template<typename T> Node<T>*& Node<T>::next()
{
    return next_;
}

template<typename T> std::ostream& operator<<(std::ostream& out, const Node<T>& N)
{
    out << N.data();
    return out;
}