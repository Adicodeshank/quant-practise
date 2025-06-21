// ===================== Trade Validator Trade Validator with Compile-Time Safety  =============
/*This project simulates a validator system for trades with strict constraints that should be verified at compile time (when possible), which is super relevant in Quant trading where compile-time safety = fewer runtime crashes or risk errors.*/
#include<iostream>
class Trade {
public:
    std::string symbol;
    double price;
    int quantity;

    Trade(std::string sym, double p , int v)
        : symbol(sym), price(p) , quantity(v){
    }
};
struct Limits {
    constexpr static double maxPrice = 1000.0;
    constexpr static double minPrice = 1.0;
    constexpr static int maxVolume = 10'000;
};
// ====================================== this won't work ===================================
// constexpr bool isvalidTrade(const Trade& t)
// {
//     constexpr requires all its arguments to be known at compile-time and trivially constructible.
//     return (t.price >= Limits::minPrice && t.price <= Limits::maxPrice && t.quantity <= Limits::maxVolume);
// }
// ============================ this will work =======================================================
constexpr bool isvalidTrade(double price, double quantity)
{
    return (price >= Limits::minPrice && price <= Limits::maxPrice && quantity <= Limits::maxVolume);
}
// constexpr Trade safeTrade = {100.0, 500, "AAPL"};// this is not working 
// because =>💥 std::string cannot be used in a constexpr constructor — it allocates memory on the heap, which is forbidden in compile-time code.
static_assert(isvalidTrade(100.0, 500), "Trade failed at compile time!");
int main()
{   
    Trade t1("AAPL", 101.2, 500);

    if(isvalidTrade(t1.price,t1.quantity))
    {
        std::cout << "Trade is valid and accepted.\n";
    }
    else
    {
        std::cout << "Trade failed validation.\n";
    }
}