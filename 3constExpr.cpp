// ================== ✅ Lambda + decltype + auto for Generic Programming (C++20 style) ===========================

#include <iostream>
#include <vector>

struct Trade {
    double price;
    int quantity;
};

int main() {
    std::vector<Trade> trades = {
        {101.2, 500},
        {99.5, 1200}
    };

    auto computeNotional = [](const Trade& t) -> decltype(t.price * t.quantity) {
        return t.price * t.quantity;
    };
    // -> se return type likhte hai lambda function ka  

    for (const auto& trade : trades) {
        auto notional = computeNotional(trade);
        std::cout << "Notional: " << notional << "\n";
    }
}
