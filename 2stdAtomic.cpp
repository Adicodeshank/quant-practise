#include<iostream>
#include<atomic>
#include<thread>
std::atomic<int> counter{0};

void task() {
    for (int i = 0; i < 500000; ++i)
        counter.fetch_add(1, std::memory_order_relaxed);
}

int main() {
    std::thread t1(task);
    std::thread t2(task);
    t1.join();
    t2.join();
    std::cout << "Final count: " << counter << "\n";
}
/*🔸 Memory Order Options
Order	                          Description
memory_order_relaxed	Atomicity only, no ordering guarantees
memory_order_acquire	Reads after can't be reordered before
memory_order_release	Writes before can't be reordered after
memory_order_acq_rel	Combines acquire + release
memory_order_seq_cst	Global sequential consistency (default, most strict)
*/