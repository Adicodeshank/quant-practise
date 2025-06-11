#include <iostream>
#include <thread>
// Example 5: Thread without join (dangerous)
void task() {
    std::cout << "Running...\n";
}

int main() {
    std::thread t(task);
    // t.join(); // If you forget this, the thread might not finish!
    t.detach(); // This means thread runs on its own, but be careful!
    std::cout << "Main ends\n";
    return 0;
}