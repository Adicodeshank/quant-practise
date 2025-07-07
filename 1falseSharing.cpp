/*🧠 1. What Is False Sharing? (Simple Explanation)
Imagine This:
You and your friend are each writing notes on the same notebook page. You’re not writing in the same place, but every time one of you writes something, the other has to wait a little, because the page keeps flipping.

That’s false sharing.

🖥️ In Programming Terms:
The notebook page is a cache line (usually 64 bytes).

You and your friend are CPU threads.

You're both writing to different variables stored in the same cache line.

Because the CPU manages cache in blocks, it gets confused and keeps reloading the whole block for both threads, even though the variables are different.

🔥 Why Is It Bad?
It causes threads to slow down.

It leads to random delays and jitter, which is really bad for:

High-frequency trading (HFT)

Live risk monitoring

Multithreaded backtesting*/

#include <thread>
#include <iostream>

struct Shared {
    int a = 0; // Thread 1 writes here
    int b = 0; // Thread 2 writes here (BUT on same cache line!)
};

Shared data;

void thread1() {
    for (int i = 0; i < 100'000'000; ++i)
        data.a++;
}

void thread2() {
    for (int i = 0; i < 100'000'000; ++i)
        data.b++;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(thread1), t2(thread2);
    t1.join(); t2.join();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Done\n";
    // bad becasue false sharing happen 
}
