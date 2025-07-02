/*🧠 1. What is Cache-Locality?
🔍 Definition:
Cache-locality means organizing memory so that data accessed together is stored closely. Modern CPUs are much faster when accessing data in contiguous chunks (cache lines) instead of scattered memory.

There are two types:

Spatial locality: Access nearby memory locations.

Temporal locality: Reuse the same memory location soon.

💥 Why it matters:
A CPU cache line is ~64 bytes.

If your data fits in nearby lines, you avoid slow memory access (RAM → CPU = slow).

This can speed up quant backtests by 10x or more.*/
#include<iostream>
#include<vector>
struct Signal {
    double score;
};
int main()
{
    // std::vector<Signal*> signals;
    // for (int i = 0; i < 1000000; ++i)
    //     signals.push_back(new Signal{(double)i});
    // Each Signal is heap-allocated, far apart in memory. Poor cache locality.

    std::vector<Signal> signals;
    for (int i = 0; i < 1000000; ++i)
        signals.push_back({(double)i});
    // All Signals are stored contiguously, one after another in memory. The CPU can prefetch efficiently.

}