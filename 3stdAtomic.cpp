#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

struct MarketData {
    std::atomic<double> bid;
    std::atomic<double> ask;
};

MarketData ticker;

void writer() {
    for (int i = 0; i < 1000; ++i) {
        ticker.bid.store(100.0 + i * 0.01, std::memory_order_release);
        ticker.ask.store(100.5 + i * 0.01, std::memory_order_release);
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }
}

void reader(int id) {
    for (int i = 0; i < 1000; ++i) {
        double b = ticker.bid.load(std::memory_order_acquire);
        double a = ticker.ask.load(std::memory_order_acquire);
        std::cout << "Reader " << id << " sees: " << b << " / " << a << "\n";
    }
}

int main() {
    std::thread w(writer);
    std::vector<std::thread> readers;

    for (int i = 0; i < 4; ++i)
        readers.emplace_back(reader, i);

    w.join();
    for (auto& r : readers) r.join();
}
