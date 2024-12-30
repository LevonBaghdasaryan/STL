#include "doubleList.hpp"

template <typename T>
Node<T>::Node(const T& value) : _data(value), _prev(nullptr), _next(nullptr) {}

template <typename T>
DoubleList<T>::DoubleList() : _head(nullptr), _tail(nullptr) {}

template <typename T>
DoubleList<T>::~DoubleList() {
    Node<T>* current = _head;
    Node<T>* temp;

    while (current) {
        temp = current->_next;
        delete current;
        current = temp;
    }
}

// Insert element at the front
template <typename T>
void DoubleList<T>::insertFront(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    if(!_head) {
        _head = _tail = newNode;
    }
    else {
        newNode->_next = _head;
        _head->_prev = newNode;
        _head = newNode;
    }
}

// Insert element at the end
template <typename T>
void DoubleList<T>::insertBack(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    if(!_tail) {
        _head = _tail = newNode;
    }
    else {
        _tail->_next = newNode;
        newNode->_prev = _tail;
        _tail = newNode;
    }
}

// Delete element from the front
template <typename T>
void DoubleList<T>::deleteFront() {
    if(!_head) return;

    Node<T>* temp = _head;
    _head = _head->_next;

    if(_head) {
        _head->_prev = nullptr;
    }
    else {
        _tail = nullptr;
    }
    
    delete temp;
}

// Delete element from the end
template <typename T>
void DoubleList<T>::deleteBack() {\
    if(!_tail) return;

    Node<T>* temp = _tail;
    _tail = _tail->_prev;

    if(_tail) {
        _tail->_next = nullptr;
    }
    else {
        _head = nullptr;
    }    

    delete temp;
}

// Display the list from front to back
template <typename T>
void DoubleList<T>::displayForward() const {
    Node<T>* current = _head;

    while (current) {
        std::cout << current->_data << " -> ";
        current = current->_next;
    }
    std::cout << "nullptr"<< std::endl;
}

// Display the list from back to front
template <typename T>
void DoubleList<T>::displayBackward() const {
    Node<T>* current = _tail;

    while (current) {
        std::cout << current->_data << " -> ";
        current = current->_prev;
    }
    std::cout << "nullptr" << std::endl;
}

template <typename T>
bool DoubleList<T>::isEmpty() const {
    return _head == nullptr;
}

template <typename T>
std::size_t DoubleList<T>::getSize() const {

    std::size_t count = 0;
    Node<T>* current = _head;

    while (current) {
        ++count;
        current = current->_next;
    }
    return count;
}