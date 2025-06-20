// ============== Mini-Project — Portfolio Valuation ========================
#include<iostream>
#include<vector>
class Position {
public:
    std::string symbol;
    double price;
    int quantity;
};

int main()
{
    std::vector<Position> portfolio = {
        {"AAPL", 182.4, 50},
        {"GOOG", 129.7, 20},
        {"MSFT", 305.1, 10},
        {"TSLA", 215.6, 5}
    };

    for(const auto& pos: portfolio)
    {
        std::cout << "Symbol" << pos.symbol << "|" 
                << "price" << pos.price << "|"
                << "volume" << pos.quantity <<"|" 
                << "Value" << pos.price*pos.quantity<<"\n"; 
    }

    double totalValue = 0.0;
    for (auto& pos : portfolio) {
        totalValue += pos.price * pos.quantity;
    }
    std::cout << "\nTotal Portfolio Value: " << totalValue << "\n";

    auto computeValue = [](const Position& p) {
        return p.price * p.quantity;
    };

    std::cout << "\nUsing computeValue() function:\n";
    for (const auto& pos : portfolio) {
        std::cout << pos.symbol << " -> $" << computeValue(pos) << "\n";
    }
}

