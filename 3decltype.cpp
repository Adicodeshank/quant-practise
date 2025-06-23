// ==== ✅ Lambda + decltype + auto for Generic Programming ) ============

#include <iostream>
#include <vector>

struct Trade {
    double price;
    int quantity;
};
class Trade2 {
    public:
    float price;
    long quantity;
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

    // task 
    auto computeNotation = [](const Trade& t)->decltype(t.price*t.quantity){
        return t.price*t.quantity;
    };
    auto computeNotation2 = [](const Trade2& t)->decltype(t.price*t.quantity){
        return t.price*t.quantity;
    };
    Trade t1 = {105.5, 200};
    auto notional4 = computeNotional(t1);
    std::cout << "Notional: " << notional4 << "\n";

    Trade2 t2 = {101.2, 500};
    auto notational5 = computeNotation2(t2);
    std::cout << "size: " << sizeof(notational5) << "\n"; // float*int = float

    double limit = 1'000'000;
    auto isRisky = [limit](const Trade& t)->decltype(t.price*t.quantity>0){
        return limit>(t.price*t.quantity);
    } ;

    if (isRisky(t1)) {
        std::cout << "⚠️ Risky Trade!\n";
    }
    // static_assert(isRisky(t2), "trade is unsafe"); // not possible becuase lambda need constexpr 


}
