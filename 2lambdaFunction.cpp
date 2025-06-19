//  Risk Filtering Engine using Lambda Functions — this simulates filtering trades/orders based on risk logic.

/*🎯 GOAL:
You’ll write a system where:
A Trade object has properties (price, volume, symbol).
A list of trades is filtered using lambda-based rules.
Only safe trades are passed to execution.*/

#include<iostream>
#include<vector>
#include<algorithm>
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

    // creating lambda function 
    std::vector<Trade> analyzedTrade;
    std::for_each(trades.begin(), trades.end(), [&](const Trade& trade){
        if(trade.price < maxPrice && trade.price > minPrice && trade.volume < maxVolume)
        {
            analyzedTrade.push_back(std::move(trade));
        }
    });

    std::for_each(analyzedTrade.begin(), analyzedTrade.end(), [](auto trade){
        std::cout << "Symbol: " << trade.symbol
                  << " | Price: " << trade.price
                  << " | Volume: " << trade.volume << "\n";
    });
}