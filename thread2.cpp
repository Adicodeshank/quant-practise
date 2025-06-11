// Example 2: Run two threads doing different tasks
#include <iostream>
#include <thread>

void task1() {
    std::cout << "Task 1 running\n";
}

void task2() {
    std::cout << "Task 2 running\n";
}

int main() {
    std::thread t1(task1);
    std::thread t2(task2);
    t1.join();
    t2.join();
    return 0;
}
