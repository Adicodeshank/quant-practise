// ===============  full Trade Risk Closure Filter mini-project =================================
#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Trade {
public:
    std::string symbol;
    double price;
    int volume;

    Trade(const std::string& sym, double p, int v)
        : symbol(sym), price(p), volume(v) {}
};


int main()
{
    double minPrice = 90.0;
    double maxPrice = 110.0;
    int maxVolume = 1000;
    std::vector<Trade> trades = 
    {
        {"AAPL", 101.2, 500},
        {"GOOG", 95.5, 1200},
        {"TSLA", 109.0, 800},
        {"AMZN", 85.0, 600},
        {"MSFT", 100.0, 300}
    };

    std::vector<std::function<bool(const Trade t)>>riskRules;

    // // Rule 1: Price must be in range
    riskRules.push_back([=](const Trade& trade){
        return trade.price >= minPrice && trade.price <= maxPrice;
    });
    // Rule 2: Volume must be below threshold
    riskRules.push_back([=](const Trade& trade){
        return trade.volume <= maxVolume;
    });


    std::vector<Trade>safeTrades;
    for (const Trade& t : trades) {
        bool isSafe = true;

        for (auto& rule : riskRules) {
            if (!rule(t)) {
                isSafe = false;
                break;
            }
        }

        if (isSafe) {
            safeTrades.push_back(t);
        }
    
    }

    for (const auto& t : safeTrades) {
    std::cout << "✅ SAFE Trade => Symbol: " << t.symbol
              << " | Price: " << t.price
              << " | Volume: " << t.volume << "\n";
    }

}