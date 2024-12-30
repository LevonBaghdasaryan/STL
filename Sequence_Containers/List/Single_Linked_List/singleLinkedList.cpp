#include "singleLinkedList.hpp"

template <typename T>
Node<T>::Node(const T& value) : _data(value), _next(nullptr) {}


template <typename T>
SingleLinkedList<T>::SingleLinkedList() : _head(nullptr), _tail(nullptr), _size(0)  {}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
    clear(); 
}

template <typename T>
void SingleLinkedList<T>::push_back(const T& value) {
    Node<T> *newNode = new Node<T>(value);
    if(_tail == nullptr) {
        _head = _tail = newNode;
    }
    else {
        _tail->_next = newNode;
        _tail = newNode;
    }
    ++_size;
}

template <typename T>
void SingleLinkedList<T>::pop_back() {
    if(_head == nullptr) {
        return;
    }

    if(_head == _tail) {
        delete _head;
        _head = _tail = nullptr;
    }
    else {
        Node<T> *temp = _head;
        while (temp->_next != _tail) {
            temp = temp->_next;
        }
        
        delete _tail;
        _tail = temp;
        _tail->_next = nullptr;
    }
    --_size;
}

template <typename T>
std::size_t SingleLinkedList<T>::getSize() const {
    return _size;
}

template <typename T>
void SingleLinkedList<T>::print() const {
    Node<T> *temp = _head;
    while(temp != nullptr) {
        std::cout << temp->_data << "->";
        temp = temp->_next;
    }
    std::cout << "nullptr" << std::endl;
}

template <typename T>
void SingleLinkedList<T>::clear() {
    while(_head != nullptr) {
        Node<T> *temp = _head;
        _head = _head->_next;
        delete temp;
    }
    _tail = nullptr;
    _size = 0;
}