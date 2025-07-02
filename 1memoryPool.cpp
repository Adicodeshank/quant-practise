// ✅ 1. What Is a Memory Pool?
// A Memory Pool is a preallocated chunk of memory from which you allocate fixed-size objects quickly — without using new/delete repeatedly.

// why it matters in quant
/*| Area                         | Benefit of Memory Pool           |
| ---------------------------- | -------------------------------- |
| High-frequency trading (HFT) | Avoids malloc latency, GC spikes |
| Order book updates           | Fast allocation/deallocation     |
| Signal caching               | Prevents fragmentation           |
| Real-time risk engines       | Predictable performance          |
*/

#include <iostream>
#include <vector>
#include <cassert>
struct Signal {
    double score;
    int id;
};

template<typename T, size_t N>
class MemoryPool {
    alignas(T) char buffer[sizeof(T) * N];
    /*✅ Step 1: Signal* s1 = pool.allocate(1.23);
    Loop over used[0]..used[999]

    First unused slot: i = 0

    used[0] = true

    Address of this slot = &buffer[0 * sizeof(Signal)] = &buffer[0]

    Placement new: new (&buffer[0]) Signal(1.23) → constructs a Signal object at buffer[0]

    Returns a Signal* pointing to buffer[0]*/
        // alignas(T) → ensures memory is properly aligned for type T (important for performance and correctness)
    bool used[N] = {}; // kaun si memory free ha kaun si khali false measn empty

public:
    T* allocate() {
        for (size_t i = 0; i < N; ++i) {
            if (!used[i]) {
                used[i] = true;
                return reinterpret_cast<T*>(&buffer[i * sizeof(T)]);
                // 🔁 reinterpret_cast turns raw memory (a char*) into a typed pointer (T*).
            }
        }
        throw std::bad_alloc(); // if no space left
    }

    void deallocate(T* ptr) {
        size_t index = (reinterpret_cast<char*>(ptr) - buffer) / sizeof(T);
        assert(index < N);
        used[index] = false; // jo index deallocate hua usko free kiya 
    }
};
int main() {
    MemoryPool<Signal, 100> pool;

    Signal* s1 = pool.allocate();
    s1->score = 0.75;
    s1->id = 1;

    Signal* s2 = pool.allocate();
    s2->score = 0.42;
    s2->id = 2;

    std::cout << "Signal1: " << s1->score << ", ID: " << s1->id << "\n";
    std::cout << "Signal2: " << s2->score << ", ID: " << s2->id << "\n";

    pool.deallocate(s1);
    pool.deallocate(s2);

    return 0;
}
/*| Alloc Type   | Location         | Latency | Fragmentation | Cache Locality | Best For                   |
| ------------ | ---------------- | ------- | ------------- | -------------- | -------------------------- |
| `new/delete` | Heap             | High    | High          | Medium         | Flexible but slow          |
| `MemoryPool` | Stack/Heap block | Low     | None          | Excellent      | Repeated small allocations |

With a pool:

Allocation = pointer math (O(1))

You never call malloc, free, or new

Fixed-size = no heap fragmentation






*/