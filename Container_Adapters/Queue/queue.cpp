#include "queue.hpp"

template <typename T>
Node<T>::Node(const T& value) : _data(value), _next(nullptr) {}

template <typename T>
Queue<T>::Queue() : _front(nullptr), _back(nullptr), _size(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if(isEmpty()) {
        _front = _back = newNode;
    }
    else {
        _back->_next = newNode;
        _back = newNode;
    }
    _size++;
}

template <typename T>
void Queue<T>::pop() {
    if(isEmpty()) {
        std::cerr << "Queue is empty, cannot pop." << std::endl;
        return;
    }

    Node<T>* temp = _front;
    _front = _front->_next;
    delete temp;

    if(_front == nullptr) {
        _back = nullptr;
    }

    _size--;
}

template <typename T>
T Queue<T>::front() const {
    if(isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return _front->_data;
}

template <typename T>
T Queue<T>::back() const {
    if(isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return _back->_data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return _front == nullptr;
}

template <typename T>
std::size_t Queue<T>::getSize() const {
    return _size;
}

template <typename T>
void Queue<T>::display() const {
    Node<T>* temp = _front;
    while (temp != nullptr) {
        std::cout << temp->_data << " -> ";
        temp = temp->_next;
    }
    std::cout << "nullptr" << std::endl;
}