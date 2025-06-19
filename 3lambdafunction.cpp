// creating lambda function with  Define filter as a std::function
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
class Trade {
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

    // creating lambda function with  Define filter as a std::function
    std::function<bool(const Trade&)> riskfilter = [&](const Trade& trade){
        return trade.price > minPrice && trade.price < maxPrice && trade.volume < maxVolume;
    };

    std::vector<Trade> filtered;
    for (const auto& trade : trades) {
        if (riskfilter(trade)) {
            filtered.push_back(trade);
        }
    }

    for (const auto& t : filtered) {
        std::cout << "SAFE: " << t.symbol << " @ " << t.price << " (Vol: " << t.volume << ")\n";
    }
}