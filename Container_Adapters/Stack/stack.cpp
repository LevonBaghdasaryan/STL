#include "stack.hpp"

template <typename T>
Stack<T>::Stack() : _head(nullptr), _size(0), _capacity(100) {}

template <typename T>
Stack<T>::Stack(std::size_t capacity) : _head(nullptr), _size(0), _capacity(capacity) {}

template <typename T>
Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(const T& value) {

    if (_size >= _capacity) {
        throw std::overflow_error("Stack Overflow");
    }

    Node<T>* newNode = new Node<T>(value);
    newNode->_next = _head;
    _head = newNode;
    ++_size;
}

template <typename T>
void Stack<T>::pop() {

    if (empty()) {
        throw std::underflow_error("Stack Underflow");
    }

    Node<T>* temp = _head;
    _head = _head->_next;
    delete temp;
    --_size;
}

template <typename T>
T& Stack<T>::top() {

    if (empty()) {
        throw std::underflow_error("Stack Underflow");
    }

    return _head->_data;
}

template <typename T>
bool Stack<T>::empty() const {
    return _head == nullptr;
}

template <typename T>
std::size_t Stack<T>::size() const {
    return _size;
}

template <typename T>
std::size_t Stack<T>::capacity() const {
    return _capacity;
}

template <typename T>
void Stack<T>::print() const {
    Node<T>* current = _head;
    if (empty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack (top to bottom): ";
    while (current != nullptr) {
        std::cout << current->_data << " ";
        current = current->_next;
    }
    std::cout << std::endl;
}