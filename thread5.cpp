#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

// Mutex to avoid output conflicts between threads
mutex mtx;

void countNumbers(string name, int start, int end) {
    for (int i = start; i <= end; i++) {
        mtx.lock();  // Lock before printing
        cout << name << " counts: " << i << endl;
        mtx.unlock();  // Unlock after printing

        this_thread::sleep_for(chrono::milliseconds(100));  // Simulate delay
    }
}

int main() {
    // Create 3 threads with different counting ranges
    thread t1(countNumbers, "Alice", 1, 5);
    thread t2(countNumbers, "Bob", 6, 10);
    thread t3(countNumbers, "Charlie", 11, 15);

    // Wait for all threads to finish
    t1.join();
    t2.join();
    t3.join();

    cout << "All counting threads are done!" << endl;

    return 0;
}
// ----------output ---------------
// Alice counts: 1
// Bob counts: 6
// Charlie counts: 11
// Alice counts: 2
// Bob counts: 7
// Charlie counts: 12
// ...
// All counting threads are done!