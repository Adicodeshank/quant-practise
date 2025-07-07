#include <future>
#include <iostream>
#include <thread>
#include <chrono>

int compute_pnl() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate heavy work
    return 137; // Pretend this is the PnL result
}

int main() {
    std::future<int> fut = std::async(std::launch::async , compute_pnl);

    std::cout << "Doing other work in main thread...\n";

    for (int i = 0; i < 5; ++i) {
        std::cout << "Tick " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    // Now get result
    int result = fut.get(); // Waits for compute_pnl() to finish
    std::cout << "PnL calculation complete: " << result << "\n";
}
/*| Component     | Where It Lives          | Notes                    |
| ------------- | ----------------------- | ------------------------ |
| `std::future` | Stack (in `main`)       | Small handle object      |
| Result value  | Heap (internal storage) | Stored by std lib        |
| Async thread  | OS thread + stack alloc | Separate from `main()`   |
| Function args | Stack (in async thread) | Local to `compute_pnl()` |
*/