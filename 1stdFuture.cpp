// #include <future>
/*What it means:
This is a header file from the C++ standard library.

It contains definitions for:

std::future

std::promise

std::async

std::packaged_task*/
#include <future>
#include <iostream>

int compute_pnl() {
    return 42;
}

int main() {
    std::future<int> fut = std::async(std::launch::async, compute_pnl);
    int result = fut.get(); // This will block until the thread is done
    std::cout << "PnL: " << result << "\n";
}

