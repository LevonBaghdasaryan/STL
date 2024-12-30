#ifndef SINGLE_LINKED_LIST_HPP
#define SINGLE_LINKED_LIST_HPP

#include <iostream>

template <typename T>
struct Node {
    T _data;
    Node<T>* _next;

    Node(const T& value);
};

template <typename T>
class SingleLinkedList {
    public:
        SingleLinkedList();
        ~SingleLinkedList();

        void push_back(const T& value);  // Add an element to the end of the list
        void pop_back();                 // Remove the last element from the list
        
        std::size_t getSize() const;

        void print() const;
        void clear();

    private:
        Node<T>* _head;     // Pointer to the first element in the list
        Node<T>* _tail;     // Pointer to the last element in the list
        std::size_t _size;  // Number of elements in the list
};

template class SingleLinkedList<int>;

#endif // SINGLE_LINKED_LIST_HPP