#include "deque.hpp"

int main() {

    try {

        Deque<int> deque;

        // Test pushing elements to the deque
        std::cout << "Pushing elements to the deque..." << std::endl;
        deque.push_back(10);
        deque.push_back(20);
        deque.push_back(30);
        deque.push_front(5);
        deque.push_front(2);

        // Print the current state of the deque
        std::cout << "Deque after pushing elements: ";
        deque.print();  // Expected: 2 5 10 20 30

        // Pop elements from the deque
        std::cout << "\nPopping elements from the deque..." << std::endl;
        deque.pop_back();
        deque.pop_front();

        // Print the deque after popping
        std::cout << "Deque after popping elements: ";
        deque.print();  // Expected: 5 10 20

        // Accessing elements using operator[]
        std::cout << "\nAccessing elements using operator[]..." << std::endl;
        std::cout << "Element at index 1: " << deque[1] << std::endl;  // Expected: 10

        // Try accessing an invalid index (this should throw an exception)
        std::cout << "Trying to access an element at an invalid index..." << std::endl;
        std::cout << "Element at index 5: " << deque[5] << std::endl;  // Should throw exception

    } 
    catch (const std::out_of_range& e) {
        std::cout << "Caught an out_of_range exception: " << e.what() << std::endl;
    }

    catch (const std::exception& e) {
        std::cout << "Caught a general exception: " << e.what() << std::endl;
    } 
    
    catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    }

    // Clearing the deque
    std::cout << "\nClearing the deque..." << std::endl;
    Deque<int> dequeClearTest;
    dequeClearTest.push_back(100);
    dequeClearTest.push_back(200);
    dequeClearTest.clear();
    std::cout << "Size after clearing: " << dequeClearTest.getSize() << std::endl;  // Expected: 0

    return 0;
}
