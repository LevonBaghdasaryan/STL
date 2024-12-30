#ifndef DOUBLE_LIST_HPP
#define DOUBLE_LIST_HPP

#include <iostream>

// Node structure to represent each element in the doubly linked list
template <typename T>
    struct Node {
        T _data;
        Node* _prev;
        Node* _next;

        Node(const T& value);
};

// Doubly Linked List class definition
template <typename T>
class DoubleList {
    public:
        DoubleList();  
        ~DoubleList(); 

        void insertFront(const T& data);  // Insert element at the front
        void insertBack(const T& data);   // Insert element at the back

        void deleteFront();               // Delete element from the front
        void deleteBack();                // Delete element from the back

        void displayForward() const;      // Display the list from front to back
        void displayBackward() const;     // Display the list from back to front

        bool isEmpty() const;             // Check if the list is empty
        std::size_t getSize() const;      // Get the size of the list

    private:
        Node<T>* _head;  // Pointer to the first element in the list
        Node<T>* _tail;  // Pointer to the last element in the list
};

template class DoubleList<int>;

#endif  // DOUBLE_LIST_HPP
