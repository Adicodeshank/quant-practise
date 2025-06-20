/*🧩 Step 1: What is auto?
📖 Definition:
auto lets the compiler deduce the type from the right-hand side of an assignment or initialization.*/
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
    int a = 5;
    auto b = a;             // b is deduced as int

    std::vector<double> prices = {100.5, 101.0, 99.8};
    auto it = prices.begin();
    // begin() function returns an iterator pointing toward the first element of the vector.

    auto sum = [](int x , int y){return x+y;};
    std::cout<< "sum is "<< sum(2,3) << "\n";

    /*The compiler figures out the type of b, it, and sum based on what’s on the right-hand side.*/

    // task 1 :
    /*Practice Tasks
    Try these to build comfort:
    Declare a vector of trades using auto.
    Iterate over them using auto& to avoid copies.
    Write a lambda that returns the notional value (price * volume) of a trade, using auto.*/
    std::vector<Trade> trades = 
    {
        {"AAPL", 101.2, 500},
        {"GOOG", 95.5, 1200},
        {"TSLA", 109.0, 800},
        {"AMZN", 85.0, 600},
        {"MSFT", 100.0, 300}
    };

    for( auto& trade:trades)
    {
        [&](){std::cout<<"Printing the price*volume"<<trade.volume*trade.price<<"\n";}();
        // this is was not untill I used Immediately invoked function expression
    }
    
    std::for_each(trades.begin(), trades.end(), [](const auto& trade){std::cout<<"Printing the price*volume"<<trade.volume*trade.price<<"\n";});
}