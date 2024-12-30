#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T> 
struct Node {
    T* _data;
    Node* _next;
    Node* _prev;
    std::size_t _capacity;
    std::size_t _size;

    Node(const std::size_t& capacity);
    ~Node();

};

template <typename T>
class Deque {
    public:
        Deque();
        ~Deque();

        void push_back(const T& value);
        void push_front(const T& value);

        void pop_back();
        void pop_front();

        // Access element at index (random access)
        T& operator[](const std::size_t& index);
        const T& operator[](const std::size_t index) const;

        bool empty() const;
        std::size_t getSize() const;

        void clear();
        void print() const;
    private:
        Node<T>* _head;         // Points to the first block
        Node<T>* _tail;         // Points to the last block
        std::size_t _size;

        static constexpr std::size_t _blockSize = 8;     // Size of each block (chunk of memory)
};

template class Deque<int>;

#endif // DEQUE_HPP