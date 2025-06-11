// Example 3: Pass data to a thread

#include <iostream>
#include <thread>

void greet(std::string name) {
    std::cout << "Hello, " << name << "\n";
}

int main() {
    std::thread t(greet, "Alice");
    t.join();
    return 0;
}

