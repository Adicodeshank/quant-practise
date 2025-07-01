//////////Mini-Project: Sort Portfolio by Risk-Adjusted Return/////////
#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip> 
#include<fstream>
struct Asset
{
    std::string name;
    double annual_return;
    double volatility;
    // sharpe ratio annual_return/volatility => It tells you how much return you get per unit of risk (volatility). High Sharpe → Better reward for the risk you take.
};
int main()
{
    std::vector<Asset> Portfolio = {
        {"AAPL", 0.12, 0.25},
        {"GOOG", 0.10, 0.15},
        {"TSLA", 0.18, 0.40},
        {"MSFT", 0.08, 0.10},
        {"AMZN", 0.09, 0.18}
    };

    
    std::sort(Portfolio.begin(), Portfolio.end(),
         [](const Asset&a, const Asset& b ){
            return ( (a.annual_return/a.volatility) > (b.annual_return/b.volatility));
         });
    
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& port : Portfolio) {
        std::cout << port.name
                  << ": Return = " << port.annual_return
                  << ", Volatility = " << port.volatility
                  << ", Sharpe = " << (port.annual_return / port.volatility)
                  << "\n";
    }

    // double r = 0.12786;
    // std::cout << "Default: " << r << "\n";
    // std::cout << std::fixed << std::setprecision(2);
    // std::cout << "Fixed 2 digits: " << r << "\n";
    // std::cout << std::setprecision(4);
    // std::cout << "Fixed 4 digits: " << r << "\n";


    ///////////////////////////////////////////////////////////////////
    std::ofstream file("portfolio_sorted.csv");
    if(!file)
    {
        std::cerr<<"error creating output file";
        return 0;
    }

    file<<"Name,Return,Volatility,Sharpe\n";
    for(const auto& port: Portfolio)
    {
        double sharpe = port.annual_return/port.volatility;
        file << port.name << ","
             << port.annual_return << ","
             << port.volatility << ","
             << sharpe << "\n";
    }
    file.close();
    std::cout << "\n✅ Portfolio exported to 'portfolio_sorted.csv'\n";
    return 0;
}

/*std::vector<Asset>:
All Asset objects are stored contiguously on the heap.
Each Asset is ~sizeof(string) + 2 * sizeof(double) ≈ small footprint.
Sorting is in-place: no additional memory allocation except stack call frames.
std::sort(...):
Uses Introsort (hybrid of quicksort + heapsort)
Time complexity: O(N log N)
Stable? No → If you want stability, use std::stable_sort*/