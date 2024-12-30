#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    T _data;
    Node* _next;

    Node(const T& value);
};

template <typename T>
class Queue {
    public:
        Queue();
        ~Queue();

        void push(const T& data);  // Adds the element at the end of the queue.
        void pop();                // Deletes the first element of the queue. 

        T front() const; // Returns a reference to the first element of the queue.
        T back() const;  // Returns a reference to the last element of the queue.

        bool isEmpty() const;
        std::size_t getSize() const;

        void display() const; 
    private:
        Node<T>* _front;  // Pointer to the front of the queue
        Node<T>* _back;   // Pointer to the rear of thr queue
        std::size_t _size;  
};

template class Queue<int>;

#endif // QUEUE_HPP