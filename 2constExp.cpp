// ============== example ============
#include<iostream>
class Trade{
public:
    static int tradecount;

    Trade(){
        tradecount++;
    }

    ~Trade()
    {
        tradecount--;
    }
}; 

int Trade::tradecount = 0; // Initializing the tradecount 

int main()
{
    Trade t1;
    Trade t2;

    std::cout << "Trade count: " << Trade::tradecount << "\n";

    {
        Trade t3;
        std::cout << "Trade count (inside scope): " << Trade::tradecount << "\n";
    }

     std::cout << "Trade count (after scope): " << Trade::tradecount << "\n";
    return 0;
}