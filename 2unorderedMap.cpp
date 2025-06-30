#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

struct Trade {
    std::string symbol;
    double price;
    int quantity;
};

std::unordered_map<std::string, int> volume_tracker;

void process_trade(const Trade& trade) {
    volume_tracker[trade.symbol] += trade.quantity;
}

void show_volume() {
    for (auto& vol  : volume_tracker)
        std::cout << vol.first << ": " << vol.second << " shares\n";
}

int main() {
    std::vector<Trade> trades = {
        {"AAPL", 180.3, 100},
        {"AAPL", 181.2, 200},
        {"GOOG", 145.1, 150},
        {"GOOG", 144.9, 100}
    };

    for (auto& t : trades) process_trade(t);
    show_volume();
}
/*| Component              | Bytes (64-bit)                             |
| ---------------------- | ------------------------------------------ |
| Key (e.g., string)     | Depends, usually heap-allocated            |
| Value (e.g., double)   | 8 bytes                                    |
| Node struct + overhead | \~32–48 bytes per element                  |
| Hash table buckets     | Grows exponentially (`load_factor` capped) |
*/