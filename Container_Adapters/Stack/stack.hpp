#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <iostream>

template <typename T>
struct Node {
    T _data;
    Node* _next;

    Node(const T& value) : _data(value), _next(nullptr) {}
};

template <typename T>
class Stack {
    public:
        Stack();
        explicit Stack(std::size_t capacity);
        ~Stack();

        void push(const T& value);
        void pop();
        T& top();

        bool empty() const;
        std::size_t size() const;
        std::size_t capacity() const;

        void print() const;
    private:
        Node<T>* _head;
        std::size_t _size;
        std::size_t _capacity;
};

template class Stack<int>;

#endif //__STACK_HPP__