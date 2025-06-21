/*.
🧠 1. What is constexpr?
🧾 Definition:
constexpr tells the compiler:
“Evaluate this value or function at compile time.”
This makes your code:
✅ Faster (no runtime computation)
✅ Safer (logic errors caught early)
✅ Leaner (fewer runtime instructions)
*/
#include<iostream>
constexpr int add(int x , int y)
{
    return x+y;
}
constexpr double fee(double price) {
    return price * 0.0005;
}
struct Limits {
    constexpr static double maxRisk = 1'000'000;
    constexpr static double minPrice = 90.0;
};
constexpr double task1(double price, double tickSize)
{
    return static_cast<int>((price/tickSize) + 0.5) * tickSize;
}
class Trade{
    public:
    static int tradeCount;  // shared across all trades

    std::string symbol;
    double price;
    int volume;

    Trade(std::string sym, double p, int v)
        : symbol(sym), price(p), volume(v) {
        ++tradeCount; 
    }

    void print() const {
        std::cout << "Trade: " << symbol << ", " << price << ", " << volume << '\n';
    }
};
int Trade::tradeCount = 0; //================ initializing trade count ======================
constexpr bool isSafeTrade(double price) {
    return price >= 90.0 && price <= 110.0;
}
int main()
{
    constexpr int   sum = add(2,3);
    std::cout<< "@ compile time calculating sum " << sum << "\n";

    // syntax 
    // constexpr double tickSize = 0.01;
    /*we can not assign a variable at run time*/

    constexpr double myFee = fee(100.0); // — computed before main() even runs

    // ===================== important example ======================== 
    double currentRisk = 950000.0;
    if(currentRisk < Limits::maxRisk)
    {
        std::cout<<"Trade is within risk limits" << "\n";
        // benefits
        /*  ✅ No object of Limits was created.
            ✅ The compiler already knows the values.
            ✅ No memory allocation — they're stored in the code section.
        */
    }


    // ================================== practise task 1 ======================================
    //🔹 Task 1: Write a constexpr function to round prices to nearest tick.
    // what is tick => is the smallest allowed price movement for financial instrument.
    constexpr double tickSize = 0.01;
    std::cout<<"task1"<<task1(105.023, tickSize) << "\n" ;
    std::cout<<"task1"<<task1(105.026, tickSize) << "\n"; 

    // ==================== task2 => Create a class with a static trade counter =================
    // int Trade::tradeCount = 0; this is too late to initialize becuase compiler needs defination of tradecount before main strats
    Trade t1("AAPL", 101.2, 500);
    Trade t2("GOOG", 99.5, 600);
    Trade t3("TSLA", 105.0, 700);

    t1.print();
    t2.print();
    t3.print();

    std::cout << "Total Trades Created: " << Trade::tradeCount << '\n';
    return 0;


    // task3 Use static_assert() to check a trade’s safety at compile time.
    // what is static_assert() => 
    /*checks a condition at compile time, not at runtime.
        If the condition fails, your program will not compile, and you’ll get a clear compiler error.*/
    // ========================= syntax ==========================
    //static_assert(condition, "Your error message if condition fails");
    /*benifits 
        static_assert() adds zero runtime cost — it disappears in the final binary.
        Catches logic bugs and design mistakes before runtime.*/
    // ex1 
    constexpr double tickSize = 0.01;
    static_assert(tickSize > 0, "Tick size must be positive");

    
    static_assert(isSafeTrade(100.0), "Unsafe trade detected!");


}

/*
Memory & Performance Analysis
    | Feature          | Memory Location        | Runtime Cost |  Notes |
| ---------------- | --------------- | ------------ | ------------------------------------------------- |
| `constexpr` var  | Code section    | 🟢 Zero      | Known at compile-time                             |
| `constexpr` func | Code section    | 🟢 Zero      | Runs at compile-time if arguments are `constexpr` |
| `static_assert`  | No memory       | 🟢 Zero      | Fails compilation before binary is created        |
✅ No heap allocations, no reallocation.
✅ No runtime penalty — fully optimized by the compiler.
*/