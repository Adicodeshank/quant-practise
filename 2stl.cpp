//==============  Mini-Project: Order Book Filter ===================
#include<iostream>
#include<vector>
#include<algorithm>
class orderBook {
    // Cleans bid prices (remove invalid values)
    // Sorts bids descending
    // Checks if any bid > threshold
    // Finds the best bid ≥ target (binary search)
    private:
    std::vector<double>bid_prices;
    public:
    void addPrices(double prices)
    {
        bid_prices.push_back(prices);
    }

    void remove_invalid_prices()
    {
        bid_prices.erase(std::remove_if(bid_prices.begin(), bid_prices.end(), [](double price){
             return price <= 0.0;
        }),bid_prices.end());
    }

    void sort_desending()
    {
        std::sort(bid_prices.begin(), bid_prices.end(), std::greater<>());
    }

    bool has_bid_above(double threshold) const {
        return std::any_of(bid_prices.begin(), bid_prices.end(), [threshold](double price) {
            return price > threshold;
    } );}

    int best_bid_at_least(double target)const
    {
        auto it = std::lower_bound(bid_prices.begin(), bid_prices.end(), target);
            if (it != bid_prices.end()) {
            return *it;
        } 
        else 
        {
            return -1;
        }
    }
    void print()
    {
            for (double p : bid_prices) {
                std::cout << p << " ";
            }
            std::cout<<"\n";
    }
};

int main() {

    orderBook ob;
    ob.addPrices(100.5);
    ob.addPrices(-1.0);   // invalid
    ob.addPrices(101.2);
    ob.addPrices(0.0);    // invalid
    ob.addPrices(99.9);
    ob.print();
   

    // cleaning invalid prices 
    ob.remove_invalid_prices();
    ob.print();
    // sort the bids desecding 
    /*
        In finance, especially in order books:
        Highest bid is best
        You want bids sorted from highest to lowest
        This helps:
        Find best bid instantly
        Run binary search correctly later
    */

    ob.sort_desending();
    ob.print();

    double alert_threshold = 101.0;
    if (ob.has_bid_above(alert_threshold)) {
        std::cout << "\nAlert: Bid above " << alert_threshold << " detected!\n";
    } else {
        std::cout << "\nNo bids above threshold.\n";
    }


    double target_price = 100.0;
    auto match = ob.best_bid_at_least(target_price);
    if (match) {
        std::cout << "\nBest bid ≥ " << target_price << ": " << match << "\n";
    } else {
        std::cout << "\nNo bid found ≥ " << target_price << "\n";
    }



}