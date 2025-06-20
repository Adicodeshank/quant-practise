// ===================== Mini-Project — Dynamic Trade Filter using Closures ======================
#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
class Trade{
    public:
    std::string symbol;
    double price;
    int volume;
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

    std::vector<std::function<bool(const Trade&)>> riskRules;
    /*📦 This creates a vector of functions that:
    Accept: const Trade& (a read-only reference to a Trade object)
    Return: bool (true if the rule passes, false if it fails)
    
    🧠 Breaking It Down Step by Step
    🔹 std::function<bool(const Trade&)>
    This means:
    “A callable thing (function, lambda, functor) that takes a const Trade& and returns a bool.”
    ex
    std::function<bool(const Trade&)> rule = [](const Trade& t) {
    return t.price < 100;
    };

    std::vector<std::function<bool(const Trade&)>>
    That just means:
    A list of rules, each of which is a function taking a Trade and returning true/false.

    for (const auto& rule : riskRules) {
        if (!rule(trade)) {
            // trade failed a rule
        }
    }
    */

    // step 1 : storing filtering lambdas 
    riskRules.push_back([=](const Trade& t){
        return t.price > minPrice && t.price < maxPrice;
    });

    riskRules.push_back([=](const Trade& t) {
        return t.volume < maxVolume;
    });

    // Step 2: Apply filters to trades
    std::vector<Trade> safeTrades;
    for(const auto& trade : trades)
    {
        bool pass = true;
        for(const auto& rule : riskRules)
        {
            if(!rule(trade))
            {
                pass = false;
                break;
            }
        }
        if (pass) {
            safeTrades.push_back(trade);
        }
    }

    for (const auto& t : safeTrades) {
        std::cout << "Symbol: " << t.symbol
                  << " | Price: " << t.price
                  << " | Volume: " << t.volume << "\n";
    }


}