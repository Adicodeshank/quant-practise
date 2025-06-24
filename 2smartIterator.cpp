#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
struct Trade {
    std::string symbol;
    double price;
    int quantity;
};

int main() {
    std::vector<Trade> trades = {
        {"AAPL", 150.5, 100},
        {"GOOG", 95.5, 300},
        {"MSFT", 110.0, 400}
    };

    // ✅ Smart Iterator — read-only traversal
    for (const auto& trade : trades) {
        std::cout << trade.symbol << " " << trade.price * trade.quantity << "\n";
    }

    // ✅ Smart Iterator — modify elements in-place
    for (auto& trade : trades) {
        trade.quantity += 10;  // increase all sizes
    }

    // ✅ Use iterators explicitly
    auto it = trades.begin();
    while (it != trades.end()) {
        std::cout << it->symbol << " updated qty: " << it->quantity << "\n";
        ++it;
    }
    // task 1 count no of trade having quantity > 100
    size_t cnt = 0;
    for(const auto& trade:trades)
    {
        if(trade.quantity > 100)
        {
            cnt++;
        }
    }
    std::cout<<"trade having quantity > 100 is: " << cnt << "\n";
    // ======================= count_if =============================
    int count = std::count_if(trades.begin(), trades.end(), [](const Trade& t){
        return t.quantity>100;
    });
    std::cout<<  "Trades with quantity > 100: " << count << "\n";

    // task 2 => Use std::for_each and a lambda to print price * quantity.
    std::for_each(trades.begin(), trades.end(), [](const Trade& t){std::cout<<t.price*t.quantity<< " ";});

    // task 3 =>Task C: Use an iterator to erase a trade with symbol "GOOG".

    // std::for_each(trades.begin(), trades.end(), [&trades](const Trade& t){if(t.symbol == "GOOG")
    // {
    //     trades.erase(t);
            // compiler error because => ❗ Never erase elements during a range-based for loop or std::for_each — they don’t expect the container to change mid-iteration.
    // }});

    // for(auto& it : trades)
    // {
    //     if(it.symbol == "GOOG")
    //     {
    //         trades.erase(it);
    //     }
    // }

    // for(int i = 0; i < trades.size(); i++)
    // {
    //     if(trades[i].symbol == "GOOG")
    //     {
    //         trades.erase(trades.begin()+i);
    //     }
    // } => not safe /////////////////////////////////////////

    // auto it = trades.begin();
    // while (it != trades.end()) {
    //     if (it->symbol == "GOOG") {
    //         it = trades.erase(it);  
    //     } else {
    //         ++it;
    //     }
    // }

    
   //////////////////// IMP /////////////////////////////
    // auto it1 = std::find_if(trades.begin(), trades.end(), [](const Trade& t) {
    //     return t.symbol == "GOOG";
    // });

    // if (it1 != trades.end()) {
    //     trades.erase(it1);
    // }

    // std::cout<<trades.size()<<"\n";

    // ================ remove_if =====================
    trades.erase(
        std::remove_if(trades.begin(), trades.end(),
            [](const Trade& t) {
                return t.symbol == "GOOG";
            }),
        trades.end()
   );
}
