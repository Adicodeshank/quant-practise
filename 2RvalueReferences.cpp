#include <iostream>
#include <vector>
#include <string>
#include <utility>  // For std::move

// Step 1: Define a Trade structure
struct Trade {
    int id;
    std::string symbol;
    double price;
    int quantity;

    Trade(int id_, const std::string& sym_, double pr_, int qty_)
        : id(id_), symbol(sym_), price(pr_), quantity(qty_) {}
};

// Step 2: Define TradeBatch class with copy and move constructors
class TradeBatch {
private:
    std::vector<Trade> trades;

public:
    // Copy constructor
    TradeBatch(const std::vector<Trade>& input) : trades(input) {
        std::cout << "Copied trades into batch\n";
    }

    // Move constructor
    TradeBatch(std::vector<Trade>&& input) : trades(std::move(input)) {
        std::cout << "Moved trades into batch\n";
    }

    void printSummary() const {
        std::cout << "Trades in batch: " << trades.size() << "\n";
        if (!trades.empty()) {
            std::cout << "First trade: " << trades[0].symbol << " @" << trades[0].price << "\n";
        }
    }
};

// Step 3: Simulate loading trades
std::vector<Trade> loadTrades() {
    std::vector<Trade> trades;
    trades.reserve(10000);  // Avoid reallocation

    for (int i = 0; i < 10000; ++i) {
        trades.emplace_back(i, "AAPL", 150.0 + i * 0.01, 100);
    }

    return trades;
}

// Step 4: Main test
int main() {
    std::vector<Trade> trades = loadTrades();

    std::cout << "Loaded trades: " << trades.size() << "\n";

    TradeBatch copied(trades);           // Copy
    TradeBatch moved(std::move(trades)); // Move

    std::cout << "After move, trades.size(): " << trades.size() << "\n";

    std::cout << "\nCopied batch summary:\n";
    copied.printSummary();

    std::cout << "\nMoved batch summary:\n";
    moved.printSummary();

    return 0;
}
