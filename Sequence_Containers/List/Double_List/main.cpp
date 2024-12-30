#include "doubleList.hpp"

int main() {

    DoubleList<int> list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);    
    list.insertBack(40);
    list.insertBack(50);    

    std::cout << "List (forward): ";
    list.displayForward();

    std::cout << "List (backward): ";
    list.displayBackward();

    list.deleteFront();
    list.deleteBack();

    std::cout << "List after deletions (forward): ";
    list.displayForward();

    return 0;
}