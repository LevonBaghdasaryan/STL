#include "stack.hpp"

int main() {

    try {
        Stack<int> stack(5); // Stack with a maximum capacity of 3

        // Pushing elements onto the stack
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

        std::cout << "Stack elements after pushing 5 elements:" << std::endl;
        stack.print();

        // Popping an element
        stack.pop();
        std::cout << "Stack elements after popping one element:" << std::endl;
        stack.print();

        // Accessing the top element
        std::cout << "Top element: " << stack.top() << std::endl;

        // Pushing more elements
        stack.push(60);
        std::cout << "Stack elements after pushing another element:" << std::endl;
        stack.print();

    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}