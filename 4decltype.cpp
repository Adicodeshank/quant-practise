// ================ Notional Engine with Type Safety =======================
#include <iostream>
#include <vector>
#include <string>

// Step 1: Trade structure
struct Trade {
    std::string symbol;
    double price;
    int quantity;

    Trade(std::string sym, double p, int q)
        : symbol(std::move(sym)), price(p), quantity(q) {}
};

// Step 2: Compile-time max notional limit
constexpr double maxNotional = 1'000'000.0;

// Step 3: constexpr compile-time safety checker
constexpr bool isSafe(double price, int quantity, double limit) {
    return (price * quantity) <= limit;
}

// Compile-time test (adjust these numbers to test!)
static_assert(isSafe(100.0, 50, maxNotional), "Trade fails compile-time safety check!");

// Step 4: Notional calculator with decltype
auto computeNotional = [](const Trade& t) -> decltype(t.price * t.quantity) {
    return t.price * t.quantity;
};

// Step 5: Runtime risk checker
auto isRisky = [=](const Trade& t) {
    return computeNotional(t) > maxNotional;
};

int main() {
    // Step 6: Sample trades
    std::vector<Trade> trades = {
        {"AAPL", 102.5, 100},
        {"GOOG", 2150.0, 4},
        {"TSLA", 999.99, 10},
        {"AMZN", 50.0, 20},
        {"MSFT", 300.0, 5000}
    };

    // Optional performance improvement
    trades.reserve(5);

    for (const auto& t : trades) {
        auto notional = computeNotional(t);

        std::cout << "Trade: " << t.symbol
                  << " | Price: " << t.price
                  << " | Quantity: " << t.quantity
                  << " | Notional: " << notional
                  << " | Type size: " << sizeof(decltype(notional))
                  << " | Risky: " << std::boolalpha << isRisky(t) << "\n";
    }

    return 0;
}
