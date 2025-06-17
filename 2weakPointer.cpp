#include<iostream>
#include<memory>
#include<vector>
// =====================================  Risk Engine Watching A Feed    ===================================================

/*You're going to build a risk engine that:
Observes market data (PriceFeed) using a std::weak_ptr (so it doesn’t keep it alive unnecessarily)
Only processes data if the feed is still active
Avoids circular memory leaks
Simulates real-world quant system architecture*/

class PriceFeed {
    /*🪜 Step 1: Define the PriceFeed class
    Responsibilities:
    Hold and print some prices
    Be constructed on the heap via std::shared_ptr*/

private:
    std::vector<double> prices;
public:
    PriceFeed(std::vector<double> p) : prices(std::move(p)) {}  ;
    void print()const
    {
        for(auto price : prices)
        {
            std::cout<< "Price" << price << " ";
        }
        std::cout<<"\n";
    }
};

class RiskEngine{
    /*🪜 Step 2: Define the RiskEngine class
    Responsibilities:
    Take a std::weak_ptr<PriceFeed> as input
    Lock the weak pointer
    If valid, call printPrices()
    If expired, report that data is unavailable*/
private:
    std::weak_ptr<PriceFeed> prices;
public:
    RiskEngine(std::weak_ptr<PriceFeed> pf) : prices(pf){};

    void moniter()
    {
        if(auto locked = prices.lock())
        {
            std::cout<< "Feed is active => risk engine" << "\n";
            locked->print();
        }
    }

};
int main()
{
    /* Step 3: In main()
    Create a shared_ptr<PriceFeed>
    Create RiskEngine using a weak_ptr to it
    Run the monitor() function before and after deleting the feed*/

    std::shared_ptr<PriceFeed> pf = std::make_shared<PriceFeed>(std::vector<double>{101.5, 102.0, 99.8});
    RiskEngine engine(pf);

    engine.moniter();  // Feed is alive

    pf.reset();  // Feed is destroyed (no more owners)
    std::cout<<"reset occur pf vaniches ";
    engine.moniter();  // Feed is gone
    return 0;
}