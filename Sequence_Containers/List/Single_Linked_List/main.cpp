#include "singleLinkedList.hpp"

int main() {

    SingleLinkedList<int> intList;

    intList.push_back(10);
    intList.push_back(20);
    intList.push_back(30);
    intList.push_back(40);
    intList.push_back(50);

    std::cout << "Size of Single Linked List: " << intList.getSize() << std::endl;
    std::cout << "Single Linked List: ";
    intList.print();

    std::cout << std::endl;

    intList.pop_back();
    std::cout << "Size of list after popping: " << intList.getSize() << std::endl;
    std::cout << "List: ";
    intList.print();

    return 0;
}