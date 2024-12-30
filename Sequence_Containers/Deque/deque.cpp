#include "deque.hpp"

template <typename T>
constexpr std::size_t Deque<T>::_blockSize;

template <typename T>
Node<T>::Node(const std::size_t& capacity) : _data(new T[capacity]), _size(0), _capacity(capacity), _next(nullptr), _prev(nullptr) {}

template <typename T>
Node<T>::~Node(){
    delete[] _data;
}


template <typename T>
Deque<T>::Deque() : _head(nullptr), _tail(nullptr), _size(0) {}

template <typename T>
Deque<T>::~Deque() {
    clear();
}

template <typename T>
void Deque<T>::push_back(const T& value) {
    if (_tail == nullptr || _tail->_size == _blockSize) {

        Node<T>* newNode = new Node<T>(_blockSize);
        if (_tail) {
            _tail->_next = newNode;
            newNode->_prev = _tail;
            _tail = newNode;
        }
        else {
            _head = _tail = newNode;
        }
    }
    _tail->_data[_tail->_size++] = value;
    ++_size;
}


template <typename T>
void Deque<T>::push_front(const T& value) {
    if (_head == nullptr || _head->_size == _blockSize) {
        
        Node<T>* newNode = new Node<T>(_blockSize);
        if (_head) {
            _head->_prev = newNode;
            newNode->_next = _head;
            _head = newNode;
        }
        else {
            _head = _tail = newNode;
        }
    }

    for (std::size_t i = _head->_size; i > 0; --i) {
        _head->_data[i] = _head->_data[i - 1];
    }

    _head->_data[0] = value;
    ++_head->_size;
    ++_size;
}


template <typename T>
void Deque<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Deque is empty");
    }

    --_tail->_size;
    --_size;

    if (_tail->_size == 0) {            // If the current tail block is empty

        Node<T>* oldTail = _tail;
        _tail = _tail->_prev;

        if (_tail) {
            _tail->_next = nullptr;
        } 
        else {                          // If there are no more blocks
            _head = nullptr;
        }

        delete oldTail;
    }
}


template <typename T>
void Deque<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Deque is empty");
    }

    for (std::size_t i = 0; i < _head->_size - 1; ++i) {
        _head->_data[i] = _head->_data[i + 1]; // Shift elements left
    }

    --_head->_size;  
    --_size;         

    if (_head->_size == 0) {           // If the current head block is empty
                   
        Node<T>* oldHead = _head;
        _head = _head->_next;

        if (_head) {
            _head->_prev = nullptr;
        } 
        else {                         // If there are no more blocks
            _tail = nullptr;
        }

        delete oldHead;
    }
}


template <typename T>
T& Deque<T>::operator[](const std::size_t& index) {

    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = _head;
    std::size_t currentIndex = index;

    while (current) {

        if (currentIndex < current->_size) {
            return current->_data[currentIndex];
        }

        currentIndex -= current->_size;
        current = current->_next;
    }

    throw std::out_of_range("Index out of range");
}


template <typename T>
const T& Deque<T>::operator[](const std::size_t index) const {

    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }

    
    Node<T>* current = _head;
    std::size_t currentIndex = index;

    while (current) {

        if (currentIndex < current->_size) {
            return current->_data[currentIndex];
        }

        currentIndex -= current->_size;
        current = current->_next;
    }

    throw std::out_of_range("Index out of range");

}


template <typename T>
bool Deque<T>::empty() const {
    return _size == 0;
}


template <typename T>
std::size_t Deque<T>::getSize() const {
    return _size;
}


template <typename T>
void Deque<T>::clear() {
    while (_head) {
        Node<T>* temp = _head;
        _head = _head->_next;
        delete temp;
    }
    _tail = nullptr;
    _size = 0;
}


template <typename T>
void Deque<T>::print() const {
    Node<T>* current = _head;
    while (current) {
        for (std::size_t i = 0; i < current->_size; ++i) {
            std::cout << current->_data[i] << " ";
        }
        current = current->_next;
    }
    std::cout << std:: endl;
}