#include <thread>
#include <iostream>

struct GoodShared {
    alignas(64) int a = 0;
    char padding[64]; // Create space (a different cache line)
    alignas(64) int b = 0;
    // You'll notice the padded version runs much faster, even though the logic is the same.
};

GoodShared data;

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
}
////////////////////////////////
/////////////////////////
/////////////////
// important
/*struct alignas(64) Slot {
    int pnl = 0;
    char pad[60]; // Padding to make the total 64 bytes
};
Slot pnl[8]; // One per thread, on separate cache lines*/
/////////////////////////
//////////////
// importnat
// Each thread should write to its own data that’s on a separate cache line.
// This is how low-latency trading engines avoid CPU stalls.

/*🧱 1. What Is alignas(64)?
alignas(64) tells the compiler:

"Make sure that this Slot starts on a 64-byte memory boundary."

🔍 Why 64?
Because CPU cache lines are typically 64 bytes long.

So by aligning a structure to 64 bytes:

You ensure each Slot gets its own cache line

You avoid false sharing between threads

🔍 2. Why Do We Align?
Let’s say you don’t use alignas(64):

struct Slot {
    int pnl = 0;
    char pad[60];
};
Even though you added padding, the compiler may still place two Slots on the same cache line — because:

There's no alignment guarantee.

It might pack them tighter together to save memory.

This means threads might still write to nearby addresses → 🚨 false sharing risk!

*/