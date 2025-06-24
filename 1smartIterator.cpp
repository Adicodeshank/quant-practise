#include<iostream>
#include<vector>
struct Trade{
    std::string symbol;
    double price;
    int quantity;
};
int main()
{
    std::vector<Trade> trades = {
        {"AAPL", 150.5, 100},
        {"GOOG", 95.5, 300},
        {"MSFT", 110.0, 400}
    };

    for(const auto& trade:trades)
    {
        std::cout<<"Notational of : "<<trade.symbol << "|"<<trade.price*trade.quantity<<"\n";
    }

    double riskLimit = 1'000'000;
    for(const auto& trade:trades)
    {
        double notational = (trade.price*trade.quantity);
        if(notational > riskLimit) continue;
        std::cout<<"safe trade only => "<<"\n";
        std::cout<<"Notational of : "<<trade.symbol << "|"<<notational<<"\n";
    }
}