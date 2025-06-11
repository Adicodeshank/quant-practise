// basic syntax for thread 
#include <iostream>
#include <thread>
void myFunction() {
    std::cout << "Hello from thread!\n";
}

int main() {
    std::thread t(myFunction);  // Create and start the thread
    t.join();                   // Wait for the thread to finish
    return 0;
}


