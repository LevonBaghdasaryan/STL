#include "queue.hpp"

int main() {

    Queue<int> queue;

    try {

        queue.push(10);
        queue.push(20);
        queue.push(30);

        std::cout << "Queue: ";
        queue.display();
        std::cout << "Front element: " << queue.front() << std::endl;
        std::cout << "Back element: " << queue.back() << std::endl;

        queue.pop();
        std::cout << "After pop, front element: " << queue.front() << std::endl;
        std::cout << "Queue: ";
        queue.display();

        std::cout << "Queue size: " << queue.getSize() << std::endl;
        std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

        // queue.push(10);
        // queue.push(20);
        // queue.push(30);

        // std::cout << "Front element: " << queue.front() << std::endl;
        // std::cout << "Back element: " << queue.back() << std::endl;

        // queue.pop();
        // queue.pop();
        // queue.pop();

        // std::cout << "Trying to access front of an empty queue...\n";
        // std::cout << "Front element: " << queue.front() << std::endl;

    } catch(std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
   
    return 0;
}    